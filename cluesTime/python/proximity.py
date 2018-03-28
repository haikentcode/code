# -*- coding: utf-8 -*-
#
# Copyright (c) 2015 -- All rights reserved.
# Author: Santosh Kumar Singh <santosh@incaendo.com>
# URL: http://www.incaendo.com
#
# This file is part of the ShopClues Master catalogue project.
#
###############################################################################


"""
spmaster
==========
"""
import nltk.corpus
import nltk.tokenize.punkt
import nltk.stem.snowball
from nltk.corpus import wordnet
import string
from spmaster.utilities import breakStringInTOWords
from spmaster import app
from functools32 import lru_cache

paths = nltk.data.path
#if '/var/nltk_data' not in paths:
#    nltk.data.path.append("/var/nltk_data");

if '/mnt/vol1/nltk_data' not in paths:
    nltk.data.path.append("/mnt/vol1/nltk_data");


#nltk.download('stopwords')

 
stopwords = nltk.corpus.stopwords.words('english')
stopwords.extend(string.punctuation)
stopwords.append('')
 
# Based on tornado.ioloop.IOLoop.instance() approach.
# See https://github.com/facebook/tornado

#wordnetConst = {"J":wordnet.ADJ,"V":wordnet.VERB,"N":wordnet.NOUN,"R":wordnet.ADV}
#hard code for above code
wordnetConst = {"J":u'a',"V":u'v',"N":u'n',"R":u'r'}
get_wordnet_pos = lambda x: (x[0],wordnetConst.get(x[1][0],wordnet.NOUN))

tokenizer = nltk.tokenize.TreebankWordTokenizer()
lemmatizer = nltk.stem.wordnet.WordNetLemmatizer()
lemmatize = lru_cache(maxsize=50000)(lemmatizer.lemmatize)



def get_proximity_match_ratio(a, b, threshold=0.8):    
    """Check if a and b are matches."""
    app.logger.info("in proximity  init with p1:%s p2:%s == %s %s" % (a,b,tokenizer.tokenize(a),tokenizer.tokenize(b)))
    pos_a = map(get_wordnet_pos,nltk.pos_tag(tokenizer.tokenize(a)))
    pos_b = map(get_wordnet_pos,nltk.pos_tag(tokenizer.tokenize(b)))
    app.logger.info("in proximity get word pos p1:%s p2:%s"%(pos_a,pos_b))

    lemmae_a = [lemmatize(token.lower().strip(string.punctuation), pos) for token, pos in pos_a \
                    if token.lower().strip(string.punctuation) not in stopwords]
    lemmae_b = [lemmatize(token.lower().strip(string.punctuation), pos) for token, pos in pos_b \
                    if token.lower().strip(string.punctuation) not in stopwords] 

    # Calculate Jaccard similarity
    app.logger.info("in proximity calculate ratio %s %s"%(a,b))
    ratio = len(set(lemmae_a).intersection(lemmae_b)) / float(len(set(lemmae_a).union(lemmae_b)))
    app.logger.info("in proximity get result %s %s %s"%(a,b,ratio))
    #return (ratio >= threshold)
    if ratio <= 0.5 and ratio > 0.3:
	from difflib import SequenceMatcher
	ratio = SequenceMatcher(None, a, b).ratio()
    words_in_v1 = breakStringInTOWords(a)
    words_in_v2 = breakStringInTOWords(b)
    word_match = 0
    for w1 in words_in_v1:
	if w1 in words_in_v2:
	    word_match = word_match + 1
    if word_match != 0:
	if len(words_in_v1) >= len(words_in_v2):
	    r = float(word_match)/len(words_in_v1)
	elif len(words_in_v1) < len(words_in_v2):
	    r = float(word_match)/len(words_in_v2)
	if r > ratio:
	    ratio = r
    app.logger.info("in proximity return result %s %s %s"%(a,b,ratio))        
    return ratio

#print get_proximity_match_ratio('Nikon Coolpix L31 Point & Shoot Camera', 'Nikon Coolpix L31 Point & Shoot Camera(Black)')

#print get_proximity_match_ratio('In the eighteenth century it was often convenient to regard man as a clockwork automaton.', 'In the 1700s, it was common to regard man as a clockwork automaton.')

#print get_proximity_match_ratio('SAMSUNG 9000 mAh for Smart Phone', 'SAMSUNG 9000 mAh for Smart Phone And Tablets')

#print get_proximity_match_ratio('5.5" Inch', '5.5 Inches Inch')
#print get_proximity_match_ratio('mahalaxmi gold coin', 'rose gold coin')
#print get_proximity_match_ratio('10 gms silver coin of lakshmi ganesh.. ', 'silver currency note of 1000 rs.')
#print breakStringInTOWords('Samsung Galaxy Tab 3 T211 Tablet (White)')
#print get_proximity_match_ratio('sony 1tb normal external hard drive (black)', 'sony 1tb wired external hard drive ()')
