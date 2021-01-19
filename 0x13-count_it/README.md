<html>
<h1>Project: Count it!</h1>
<p><strong>In this project we'll review an exercise where we have to query the Reddit API and mold the response in order to get a desired output</strong></p>
<body>
<li><strong>Task 0:</strong> Write a recursive function that queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. Javascript should count as javascript, but java should not).

Requirements:
<ul>
<li>Prototype: def count_words(subreddit, word_list)</li>
<li>Note: You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.</li>
<li>If word_list contains the same word (case-insensitive), the final count should be the sum of each duplicate (example below with java)</li>
<li>Results should be printed in descending order, by the count, and if the count is the same for separate keywords, they should then be sorted alphabetically (ascending, from A to Z). Words with no matches should be skipped and not printed. Words must be printed in lowercase.</li>
<li>Results are based on the number of times a keyword appears, not titles it appears in. java java java counts as 3 separate occurrences of java.</li>
<li>To make life easier, java. or java! or java_ should not count as java</li>
<li>If no posts match or the subreddit is invalid, print a newline.</li>
<li>NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.</li>
</ul>
Your code will NOT pass if you are using a loop and not recursively calling the function! This /can/ be done with a loop but the point is to use a recursive function. :)

Disclaimer: number presented in this example cannot be accurate now - Reddit is hot articles are always changing.
</li>
</body>
<br>
<br>
<footer>Made by: <strong><a href="https://github.com/DanielBaquero28">Daniel Baquero</a></strong></footer>
</html>
