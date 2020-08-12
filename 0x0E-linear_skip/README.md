<html>
<h1>Project: Linear Skip</h1>
<p><strong>In this project we'll understand how skip lists work and how are they a good alternative when searching for a value in a sorted singly linked list.</strong></p>
<body>
<li><strong>Task 0:</strong> Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a skip list.

Write a function that searches for a value in a sorted skip list of integers.
<ul>
<li>Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);</li>
<li>Where list is a pointer to the head of the skip list to search in</li>
<li>A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)</li>
<li>And value is the value to search for</li>
<li>You can assume that list will be sorted in ascending order</li>
<li>Your function must return a pointer on the first node where value is located</li>
<li>If value is not present in list or if head is NULL, your function must return NULL</li>
<li>Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)</li>
</ul>
</li>
</body>
<br>
<br>
<footer>Made by: <strong><a href="https://github.com/DanielBaquero28">Daniel Baquero</a></strong></footer>
</html>