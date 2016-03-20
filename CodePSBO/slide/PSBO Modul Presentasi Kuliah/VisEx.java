class BinTreeNode
{
	private BinTreeNode left = null;
	private BinTreeNode right = null;
	private String value;

	public BinTreeNode (String val)
	{
		this.value = val;
	}	

	public  String getValue()
	{
		return value;
	}

	public BinTreeNode getLeft()
	{
		return left;
	}

	public BinTreeNode getRight()
	{
		return right;
	}

	public void setRight(BinTreeNode n)
	{
		this.right = n;
	}
	
	public void setLeft(BinTreeNode n)
	{
		this.left = n;
	}
	public void accept(BTVisitor v)
	{
		//v.visit(this.value);
		if(this.left != null)
			v.visit(this.left);

		//v.visit(this.value);

		if(this.right!=null)
			v.visit(this.right);
		v.visit(this.value);
	}
}

interface BTVisitor
{
	void visit(BinTreeNode n);
	void visit(String s);
}

class PrintVisitor implements BTVisitor
{
	public void visit(BinTreeNode n)
	{
		System.out.print("(");
		n.accept(this);
		System.out.print(")");
	}
	public void visit(String v)
	{
		System.out.print(v);
	}
}

/*
class EvalVisitor implements BTVisitor
{	
	public void visit(BinTreeNode n)
	{
	}
	public void visit(String v)
	{
		if(tidak_ada_child)
			value = Integer.parseInt(v);
		else
		{
			leftvalue = value_dari_left_child;
			rightvalue = value_dari_right_child;
			value = leftvalue op rightvalue
		}
	}
}
*/

public class VisEx
{
	public static void main(String[] args)
	{
		/* (4+2)*3 */
		BinTreeNode o = new BinTreeNode("*");
		BinTreeNode a = new BinTreeNode("+");
		BinTreeNode a1 = new BinTreeNode("4");
		BinTreeNode a2 = new BinTreeNode("2");
		BinTreeNode b = new BinTreeNode("3");
		o.setLeft(a);
		a.setLeft(a1);
		a.setRight(a2);
		o.setRight(b);

		BTVisitor v = new PrintVisitor();
		o.accept(v);

		v = new EvalVisitor();
		o.accept(v);
	}
}