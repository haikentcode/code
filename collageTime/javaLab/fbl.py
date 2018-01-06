import facebook
graph = facebook.GraphAPI()
profile = graph.get_object("me")
friends = graph.get_connections("me", "friends")
graph.put_object("me", "feed", message="I am writing on my wall!")
