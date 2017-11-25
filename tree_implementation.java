/**
 * Monday, March 23, 2009 6:47:08 PM
 * Subject: coms 101-tree implementation
 */
class Tree
{
  private Node r;

  public Tree()
  {
    r = null;
  }

  public Node find(int key)
  {
    Node current = r;
    while(current.element != key)
    {
      if(key < current.element)
      current = current.left;
      else

      current = current.right;

      if(current == null)
      return null;
    }

    return current;
  }

  public void insert(char id, double dd)
  {
    Node newNode = new Node();
    newNode.element = id;
    newNode.dData = dd;

    if(r==null)
    r = newNode;
    else
    {
      Node current = r;
      Node parent;
      while(true)
      {
        parent = current;
        if(id < current.element) {
          current = current.left;
          if(current == null) {
            parent.left = newNode;
            return;
          }
        } else {
          current = current.right;
          if(current == null) {
            parent.right = newNode;
            return;
          }
        }
      }
    }
  }

  public boolean delete(int key)
  {
    Node current = r;
    Node parent = r;
    boolean isleft = true;
    while(current.element != key)
    {
      parent = current;
      if(key < current.element) {
        isleft = true;
        current = current.left;
      } else {
        isleft = false;
        current = current.right;
      }

      if(current == null)
      return false;
    }

    if(current.left==null &&current.right==null) {
      if(current == r)
        r = null;
      else if(isleft)
        parent.left = null;
      else
        parent.right = null;
    }
    // if no right child, replace with left subtree
    else if(current.right==null)
    if(current == r)
    r = current.left;
    else if(isleft)
    parent.left = current.left;
    else
    parent.right = current.left;
    // if no left child, replace with right subtree
    else if(current.left==null)
    if(current == r)
    r = current.right;
    else if(isleft)
    parent.left = current.right;
    else
    parent.right = current.right;
    else  // two children, so replace with inorder successor
    {

      Node successor = getSuccessor(current);

      if(current == r)
      r = successor;
      else if(isleft)
      parent.left = successor;
      else
      parent.right = successor;

      successor.left = current.left;
    }

    return true;
  }

  private Node getSuccessor(Node delNode)
  {
    Node successorParent = delNode;
    Node successor = delNode;
    Node current = delNode.right;
    while(current != null)
    {
      successorParent = successor;
      successor = current;
      current = current.left;
    }

    if(successor != delNode.right)
    {
      successorParent.left = successor.right;
      successor.right = delNode.right;
    }
    return successor;
  }

  public void traverse(int traverseType)
  {
    switch(traverseType)
    {
      case 1: System.out.print("\nPreorder traversal: ");
      preOrder(r);
      break;
      case 2: System.out.print("\nInorder traversal:  ");
      inOrder(r);
      break;
      case 3: System.out.print("\nPostorder traversal: ");
      postOrder(r);
      break;
    }
    System.out.println();
  }

  private void preOrder(Node localr)
  {
    if(localr != null)
    {
      System.out.print(localr.element + " ");
      preOrder(localr.left);
      preOrder(localr.right);
    }
  }

  private void inOrder(Node localr)
  {
    if(localr != null)
    {
      inOrder(localr.left);
      System.out.print(localr.element + " ");
      inOrder(localr.right);
    }
  }

  private void postOrder(Node localr)
  {
    if(localr != null)
    {
      postOrder(localr.left);
      postOrder(localr.right);
      System.out.print(localr.element + " ");
    }
  }

  public void displayTree()
  {
    Stack globalStack = new Stack();
    globalStack.push(r);
    int nBlanks = 32;
    boolean isRowEmpty = false;
    System.out.println("......................................................");
    while(isRowEmpty==false)
    {
      Stack localStack = new Stack();
      isRowEmpty = true;
      for(int j=0; j<nBlanks; j++)
      System.out.print(' ');
      while(globalStack.isEmpty()==false)
      {
        Node temp = (Node)globalStack.pop();
        if(temp != null)
        {
          System.out.print(temp.element);
          localStack.push(temp.left);
          localStack.push(temp.right);
          if(temp.left != null ||
          temp.right != null)
          isRowEmpty = false;
        }
        else
        {
          System.out.print("--");
          localStack.push(null);
          localStack.push(null);
        }
        for(int j=0; j<nBlanks*2-2; j++)
        System.out.print(' ');
      }
      System.out.println();
      nBlanks /= 2;
      while(localStack.isEmpty()==false)
      globalStack.push( localStack.pop() );
    }
    System.out.println("......................................................");
  }
}
