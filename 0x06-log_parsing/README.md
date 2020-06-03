<html>
<h1>Project: Log Parsing</h1>
<p><strong>In this project we'll review how to parse and present correctly logs.</strong></p>
<body>
<li><strong>Task 0:</strong> Write a script that reads stdin line by line and computes metrics:
<ul>
<li>Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size></li>
<li>After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
<ul>
<li>Total file size: File size: <total size></li>
<li>where <total size> is the sum of all previous <file size> (see input format above)
</li>
<li>Number of lines by status code:
<ul>
<li>possible status code: 200, 301, 400, 401, 403, 404, 405 and 500</li>
<li>if a status code doesn’t appear, don’t print anything for this status code</li>
<li>format: <status code>: <number></li>
<li>status codes should be printed in ascending order</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</body>
<br>
<br>
<footer>Made by: <strong><a href="https://github.com/DanielBaquero28">Daniel Baquero</a></strong></footer>
</html>