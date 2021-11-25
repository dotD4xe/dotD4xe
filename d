s1 = str(input("Please enter a string: "))
s2 = str(input("Please enter a string: "))
s1.replace(" ","")
s2.replace(" ","")
i = 0
max = ""
while i < len(s1):
    sb = ""
    j=0
    while j < len(s2) and s1[i] != s2[j]:
        j += 1
    z = i
    while z < len(s1) and j < len(s2) and s1[z] == s2[j]:
        sb += (s2[j])
        j += 1
        z += 1
    if len(max) < len(sb):
        max = sb
    i += 1
print("Самое длинное совпадение в строках", s1," и ",s2 ," : ", ma
