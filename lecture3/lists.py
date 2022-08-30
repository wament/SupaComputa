
""" LIST METHODS """

print("list append")
list1 = [1, 2, 3]
print(id(list1), list1)
list1.append(4)
print(id(list1), list1, "\n")

list2 = list(list1)

print("list clear")
list1.clear()
print(id(list1), list1, "\n")

print("list copy")
print(id(list2), list2, "\n")


list2.append(2)
list2.append(2)
list2.append(2)
print("list count")
print(id(list2), list2)
print("There are", list2.count(2), "twos in list2. \n")


list2.extend([11,12,13])
print("list extend")
print("list 2 has been extend with [11, 12, 13]")
print(id(list2), list2, "\n")


print("list index")
print("The first occurence of 2 is at index 1")
print(list2.index(2), "\n")

print("list insert")
list2.insert(2, 7)
print("A 7 has been inserted into list 2 and index 2.")
print(id(list2), list2, "\n")

print("list pop")
list2.pop()
print("13, the last element of list2, has been popped from the list.")
print(id(list2), list2, "\n")

print("list remove")
list2.remove(2)
print("The first occurence of two has been removed from the list.")
print(id(list2), list2, "\n")

print("list reverse")
list2.reverse()
print("The list has now been reversed.")
print(id(list2), list2, "\n")

print("list sort")
list2.sort()
print("The list has now been sorted")
print(id(list2), list2, "\n")
