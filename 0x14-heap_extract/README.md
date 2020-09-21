<html>
	<header><h1>Project: Heap Extract</h1></header>
	<body>
		<p><strong>In this project we'll be reviewing the Max Binary Heap data structure. We'll understand why it's important and when should we implement it.</strong></p>
		<ul>
			<li><strong>Task 0: </strong>Write a function that extracts the root node of a Max Binary Heap:
					 <ul>
						<li>Prototype: int heap_extract(heap_t **root);</li>
						<li>root is a double pointer to the root node of the heap</li>
						<li>Your function must return the value stored in the root node</li>
						<li>The root node must be freed and replace with the last level-order node of the heap</li>
						<li>Once replaced, the heap must be rebuilt if necessary</li>
						<li>If your function fails, return 0</li>
					 </ul>
			<p>Note: In order for the main file to compile, you are provided with this static library. This library won’t be used during correction, its only purpose is for testing.</p>
			</li>
		</ul>
	</body>
	<footer>Made by: <strong><a href="https://github.com/DanielBaquero28">Daniel Baquero</a></strong></footer>
</html>