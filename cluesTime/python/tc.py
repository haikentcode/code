from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans ,MiniBatchKMeans
from sklearn.metrics import adjusted_rand_score
import math

def kmensAlgo(documents,k=20):
         print "document Size",len(documents)
         vectorizer = TfidfVectorizer(stop_words='english')
         X = vectorizer.fit_transform(documents)
         true_k = k
         model = MiniBatchKMeans(n_clusters=true_k, init='k-means++', max_iter=200, n_init=1)
         model.fit(X)
         return model.predict(X)


if __name__ == "__main__":
    document =["rock music", "rockon","love life","newday","sunsine","moring","rockon pary","partymood"]
    print kmensAlgo(document,3)
