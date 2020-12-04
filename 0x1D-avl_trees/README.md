<html>
<h1>Project: AVL Trees</h1>
<p><strong>In this project we'll review AVL Trees, which is a self-balancing Binary Search Tree, where the difference between the left and the right subtree is never ore than one for all of the nodes.</strong></p>
<body>
<li><strong>Task 0:</strong> Write a function that checks if a binary tree is a valid AVL Tree
<ul>
<li>Prototype: int binary_tree_is_avl(const binary_tree_t *tree);</li>
<li>Where tree is a pointer to the root node of the tree to check</li>
<li>Your function must return 1 if tree is a valid AVL Tree, and 0 otherwise</li>
<li>If tree is NULL, return 0</li>
</ul>
<p>Properties of an AVL Tree:</p>
<ul>
<li>An AVL Tree is a BST</li>
<li>The difference between heights of left and right subtrees cannot be more than one</li>
<li>The left and right subtree each must also be a binary search tree</li>
</ul>
<p>Note: In order for the main file to compile, you are provided with this static library. This library won’t be used during correction, its only purpose is for testing.</p>
</li>
</body>
<br>
<br>
<footer>Made by: <strong><a href="https://github.com/DanielBaquero28">Daniel Baquero</a></strong></footer>
</html>
