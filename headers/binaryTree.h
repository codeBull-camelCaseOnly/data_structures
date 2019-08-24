/*COPYRIGHT 'Kross707' @github */
#pragma once
#include<iostream>
#include<GL/glew.h>				//
#include<GLFW/glfw3.h>			//
#include<GL/freeglut.h>			//openGL libraries
#include<string>		

const double PI = 3.141592653589;

/*
'dx' here is for initial horizontal distance between nodes in the visualizer. 
It decreases as we move down the tree, to occupy the space for all nodes
*/
const double dx = 150;					

/*
Yeah! Generic Programming in action.
*/
template <typename T>
struct Node
{
	T data;
	int level;	//denoting the level of Tree Node, root node is 0 , first children is 1, second children is 2 and so on...
	int x, y;	//position of Node in visualizing screen
	Node* left, * right;	//denoting the left and right nodes for each node.
	Node()
	{
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class binaryTree
{
private:
	Node<T>* root;		//root node(or parent node) is the topmost one in any tree
	
	
	/*PRIVATE MEMBER FUNCTION*/

	/*
	"circle" function is as it suggests, a function which draws a circle on the screen using the centre 
	coordinates and text to be displayed in the circle.(Not sure why I took string in the first place... 
	Why would anyone display string inside binary tree???)
	*/
	void circle(double x, double y, std::string str)
	{
		/*this section is used for drawing the circle*/
		int r = 20, n = 20;		//radius and precision factor for circle.(Increase 'n' for getting better but slow circle graphics)
		glColor3f(100, 0, 0);	//fill color for the circle
		glBegin(GL_POLYGON);
		for (double i = 0; i < 360; i += 360 / n)
		{
			/*
			NOTE: I have drawn circle using 3d coordinates and not 2d so I can implement it layer by layer.
			i.e. circle is displayed 'over' lines and text is displayed 'over' circle
			see the values of 3rd coordinates for circle, line and text if you are still confused
			*/
			glVertex3f(x + r * cos(i * PI / 180), y + r * sin(i * PI / 180), 0.5);
		}
		glEnd();


		/*this section is used for drawing connecting lines between circles*/
		glColor3f(100, 100, 100);		//color of lines
		liner(root);					
		

		/*
		THIS SECTION WAS USED TO DRAW OUTLINE OF CIRCLE BUT REMOVED LATER.
		glColor3f(0, 0, 200);
		glBegin(GL_LINE_LOOP);
		for (double i = 0; i < 360; i += 360 / n)
		{
			glVertex3f(x + r * cos(i * PI / 180), y + r * sin(i * PI / 180), 0.5);
		}
		glEnd();
		*/

		/*this section is for drawing text*/
		glColor3f(256, 256, 256);	//text color
		int siz = str.size();		
		
		glRasterPos3i(x - 3.5 * siz, y, 1);			//position of text inside circle. came up with trial and error
		for (int i = 0; i < siz; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);	//Yeah I know this is depreceated... But fast to code
		}

		
	}  

	/*
	"liner" function displays line connecting parent to child
	It is implemented independently because it is achieved through recursive technique 
	*/
	void liner(Node<T>* current)
	{
		/*
		Simple to understand...
		*/
		if (current != nullptr)
		{
			if (current->left != nullptr)
			{
				glBegin(GL_LINES);
				glVertex2f(current->x, current->y);
				glVertex2f(current->left->x, current->left->y);
				glEnd();
				liner(current->left);
			}

			if (current->right != nullptr)
			{
				glBegin(GL_LINES);
				glVertex2f(current->x, current->y);
				glVertex2f(current->right->x, current->right->y);
				glEnd();
				liner(current->right);
			}
		}
	}

	/*
	This function is used to call "circle" function for each Node through recursion
	*/
	void visualize(Node<T>* current)
	{
		if (current != nullptr)
		{
			circle(current->x, current->y, std::to_string(current->data));
			if (current->left != nullptr)
				visualize(current->left);
			if (current->right != nullptr)
				visualize(current->right);
		}
	}

	/*
	displays the data of each node through recursion
	*/
	void displayer(Node<T> *current)
	{
		if (current != nullptr)
		{
			std::cout << current->data << "\n";
			if (current->left != nullptr)
				displayer(current->left);
			if (current->right != nullptr)
				displayer(current->right);
		}
	}

	/*
	deleting the tree through recursion
	*/
	void deleter(Node<T>* current)
	{
		if (current != nullptr)
		{
			deleter(current->left);
			deleter(current->right);
			delete current;
		}
	}

public:
	binaryTree()
	{
		root = nullptr;
	}

	/*
	Long function.
	read carefully
	*/
	void add(T data)
	{
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->level = 0;
		

		if (root == nullptr)
		{
			temp->x = 400;		//position of root in visualizer
			temp->y = 100;		//   ''	   ''  ''  ''	 ''
			root = temp;
		}
		else
		{
			Node<T>* iterator;
			iterator = root;
			while (1)
			{
				temp->level++;  //Increasing level of node as we move down the tree
				if (data <= iterator->data)		//If you dont understand this, you might want to revisit wiki article for binary trees
				{
					if (iterator->left == nullptr)
					{
						temp->x = iterator->x - dx/(temp->level);	
						//Every child node on the left has its x coordinate little left to its parent node
						//And it decreases as we move down to fit in all nodes thats why divided by temp->level
						temp->y = iterator->y + dx;
						//y coordinate of child node is below parent node
						iterator->left = temp;
						break;
					}
					else
					{
						iterator = iterator->left;
					}
				}
				else if (data > iterator->data)
				{
					if (iterator->right == nullptr)
					{
						temp->x = iterator->x + dx / (temp->level);
						//Every child node on the right has its x coordinate little right to its parent node	
						//And it decreases as we move down to fit in all nodes thats why divided by temp->level
						temp->y = iterator->y + dx;
						//y coordinate of child node is below parent node
						iterator->right = temp;
						break;
					}
					else
					{
						iterator = iterator->right;
					}
				}
			}
		}

	}

	/*
	essence of binary tree, the "search" function
	easy to understand, so no comments inside
	returns the Node itself so that user can modify it
	*/
	Node<T>* search(T data)
	{
		Node<T>* current;
		current = root;
		while (current != nullptr)
		{
			if (current->data == data)
				return current;
			else if (current->data > data)
				current = current->left;
			else current = current->right;
		}
		return nullptr;
	}

	/*
	calling private member function with 'root' for recursion
	*/
	void display()
	{
		displayer(root);
	}

	/*
	Don't read if you do not know openGL and glfw
	*/
	void visualizer()
	{
		glfwInit();		//initializing of glfw

		int argc = 1;
		char *argv[1] = {" "};
		glutInit(&argc, argv);	//for GLUT members usage

		GLFWwindow* window = glfwCreateWindow(800, 600, "Binary Tree Visualizer", nullptr, nullptr);  //window size and title
		glfwMakeContextCurrent(window);

		glMatrixMode(GL_PROJECTION);	
		gluOrtho2D(0, 800, 600, 0);			//defining top left as (0,0) and bottom right as (800, 600)

		glEnable(GL_DEPTH_TEST);		// for displaying things over each other

		while (!glfwWindowShouldClose(window))		//main loop
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clearing screen and depth
			visualize(root);		//main content

			glfwSwapBuffers(window);		//double buffering
			glfwPollEvents();	
		}

		glfwTerminate();	//ending of application
	}

	/*
	destructor
	*/
	~binaryTree()
	{
		deleter(root);
	}
};