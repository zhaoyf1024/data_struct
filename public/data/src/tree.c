#include "tree.h"

pTree treeCreate()
{
    pTree newtree;
    newtree = (pTree)calloc(1, sizeof(Tree));
    if(!newtree)
        return NULL;

    return newtree;
}

int getDepth(avpNode node)
{
    if(!node)
        return 0;

    return MAX(getDepth(node->lchild), getDepth(node->rchild)) + 1;
}

void nodeInit(avpNode node)
{
    node->lchild = node->rchild = node->parent = NULL;
    node->balance = node->depth = 0;
}

void setLeftChild(avpNode parent, avpNode child)
{
    child->parent = parent;
    child->depth = parent->depth + 1;
    parent->lchild = child;
}

void setRightChild(avpNode parent, avpNode child)
{
    child->parent = parent;
    child->depth = parent->depth + 1;
    parent->rchild = child;
}

avpNode LL_rotate(avpNode node)
{
    avpNode parent = NULL;
    avpNode rotate = NULL;
    
    parent = node->parent;
    rotate = node->lchild;

    if (rotate->rchild != NULL)
    {
        rotate->rchild->parent = node;
        node->lchild = rotate->rchild;
    }
    else
    {
        node->lchild = NULL;
    }
    
    rotate->rchild = node;
    rotate->parent = parent;

    if (parent != NULL)
    {
        if (parent->lchild == node) parent->lchild = rotate;
        else parent->rchild = rotate;
    }
    
    node->parent = rotate;

    return rotate;
}

avpNode RR_rotate(avpNode node)
{
    avpNode parent = NULL;
    avpNode rotate = NULL;
    
    parent = node->parent;
    rotate = node->rchild;

    if (rotate->lchild != NULL)
    {
        rotate->lchild->parent = node;
        node->rchild = rotate->lchild;
    }
    else
    {
        node->rchild = NULL;
    }
    
    rotate->lchild = node;
    rotate->parent = parent;

    if (parent != NULL)
    {
        if (parent->lchild == node) parent->lchild = rotate;
        else parent->rchild = rotate;
    }
    node->parent = rotate;

    return rotate;
}
 
avpNode LR_rotate(avpNode node)
{  
    RR_rotate(node->lchild);
    return LL_rotate(node);
}
 
avpNode RL_rotate(avpNode node)
{
    LL_rotate(node->rchild);
    return RR_rotate(node);
}

void balance(avpNode node)
{
    if(!node)
        return;
        
    node->balance = getDepth(node->lchild) - getDepth(node->rchild);
    //printf("bf:[%d]\n",node->balance);
    balance(node->lchild);
    balance(node->rchild);   
}

avpNode ads(pTree tree, avpNode node)
{
    while (node!=NULL) 
   {
       if (node->balance > 1 || node->balance < -1) 
       {
           if (node->balance > 1) 
           {
               if (node->lchild->balance > 0) node = LL_rotate(node);//LL
               else node = LR_rotate(node);//LR
           }
           else 
           {
               if (node->rchild->balance < 0) node=RR_rotate(node);//RR
               else node=RL_rotate(node);//RL
           }
           if (node->parent == NULL) 
           {
               tree->root = node; 
               break; 
           }
       }
       node = node->parent; 
       
   }
   balance(tree->root);
   
   return tree->root;    
}

void insertRoot(pTree tree, avpNode node)
{
    tree->root = node;
}

void insertLeft(pTree tree, avpNode parent, avpNode insert)
{
    setLeftChild(parent, insert);  
    //printf("lchild:[%d] balance:[%d]\n",parent->lchild->hash, getDepth(tree->root->lchild)-getDepth(tree->root->rchild));
    balance(tree->root);
    ads(tree, parent);
}

void insertRight(pTree tree, avpNode parent, avpNode insert)
{
    setRightChild(parent, insert);
    //printf("rchild:[%d] balance:[%d]\n",parent->rchild->hash, getDepth(tree->root->lchild)-getDepth(tree->root->rchild));
    balance(tree->root);
    ads(tree, parent);
}

void deleteNode(pTree tree, avpNode parent, avpNode del)
{  
    avpNode tnode;
    int temp;
    if(del->lchild && del->rchild) //del有左右子树
    {
        if(del->balance > -1)//前驱节点替换
        {
            tnode = del->lchild;
            while(tnode->rchild)
            {
                tnode = tnode->rchild;
            }
        
            temp = del->hash;
            del->hash = tnode->hash;
            tnode->hash = temp;
            if(tnode->parent->lchild == tnode)
                tnode->parent->lchild = NULL;
            else
                tnode->parent->rchild = NULL;
            tnode->parent = NULL;
        }
        else//后继节点替换
        {
            tnode = del->rchild;
            while(tnode->lchild)
            {
                tnode = tnode->lchild;
            }
        
            temp = del->hash;
            del->hash = tnode->hash;
            tnode->hash = temp;
            tnode->parent->lchild = NULL;
            tnode->parent = NULL;
        }
    }
    else if(del->lchild)//del 只有左子树
    {
        tnode = del->lchild;
        temp = del->hash;
        del->hash = tnode->hash;
        tnode->hash = temp;
        tnode->parent = NULL;
        del->lchild = NULL;
    }
    else if (del->rchild)//del 只有右子树
    {
        tnode = del->rchild;
        temp = del->hash;
        del->hash = tnode->hash;
        tnode->hash = temp;
        tnode->parent = NULL;
        del->rchild = NULL;
    }
    else //del为叶子节点
    {
        if(parent->lchild && parent->lchild->hash == del->hash) parent->lchild = NULL;
        else if(parent->rchild && parent->rchild->hash == del->hash) parent->rchild = NULL;
        del->parent = NULL;
    }
    
    balance(tree->root);
    ads(tree, parent);
}

void treeInsertNode(pTree tree, avpNode node)
{
    if(tree == NULL || node == NULL)
        return;

    avpNode parent;
    nodeInit(node);  

    if(tree->root == NULL)
    {
        insertRoot(tree, node);
        //printf("root:[%d] balance:[%d]\n",tree->root->hash, getDepth(tree->root->lchild)-getDepth(tree->root->rchild));
        return;
    }
    
    for(parent = tree->root; parent;)
    {
        if(COMPAREAVNODE(node, parent)) 
        {
            if(parent->lchild) {
                parent = parent->lchild;
            } else {
                insertLeft(tree, parent, node);
                return;
            }
        }
        else
        {
            if(parent->rchild) {
                parent = parent->rchild;
            } else {
                insertRight(tree, parent, node);
                return;
            }
        }
    }
}

void treeDeleteNode(pTree tree, avpNode node)
{
    if(tree == NULL || node == NULL)
        return;
    
    avpNode del, parent;
    
    for(del = tree->root; del;)
    {
        if(node->data != del->data) 
        {
            if(node->data < del->data) del = del->lchild;
            else del = del->rchild;
        }
        else if(node->data == del->data)
        {
            parent = del->parent;
            deleteNode(tree, parent, del);
            return;
        }
        else
        {
            printf("node no find\n");
            return;
        }
    }
}



void PreOrder(avpNode root)
{
    if (root == NULL)
        return;
        
    printf("%d ", root->hash);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void InOrder(avpNode root)
{
    if (root == NULL)
        return;
        
    InOrder(root->lchild);
    printf("%d ", root->hash);
    InOrder(root->rchild);
}


void PostOrder(avpNode root)
{
    if (root == NULL)
        return;
        
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%d ", root->hash);
}

