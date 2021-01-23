#!/usr/bin/python3
""" This must be done recursively """
import requests


def count_words(subreddit, word_list, next_page=None, kw_count={}, kw_dup={}):
    """
    Write a recursive function that queries the Reddit API, parses
    the title of all hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count
    as javascript, but java should not).
    """
    headers = {'User-Agent': 'DanielBaquero28'}

    if next_page:
        response = requests.get(
            'https://reddit.com/r/' + subreddit + '/hot.json?after=' +
            next_page, headers=headers)
    else:
        response = requests.get(
            'https://reddit.com/r/' + subreddit + '/hot.json', headers=headers)

    if response.status_code == 404:
        return

    if kw_count == {}:
        for kw in word_list:
            kw_count[kw] = 0
            kw_dup[kw] = word_list.count(kw)

    response_dict = response.json()
    response_data = response_dict['data']
    next_page = response_data['after']
    response_articles = response_data['children']

    for article in response_articles:
        article_data = article['data']
        article_title = article_data['title']
        title_wl = article_title.split()

        for word in title_wl:
            for key in kw_count:
                if word.lower() == key.lower():
                    kw_count[key] += 1

    if next_page:
        count_words(subreddit, word_list, next_page, kw_count, kw_dup)
    else:
        for key, value in kw_dup.items():
            if value > 1:
                kw_count[key] *= value

        sort_kw_dict = sorted(kw_count.items(), key=lambda x: x[0])
        final_sort = sorted(sort_kw_dict, key=lambda x: (-x[1], x[0]))

        for sort in final_sort:
            if sort[1] > 0:
                print('{}: {}'.format(sort[0], sort[1]))
