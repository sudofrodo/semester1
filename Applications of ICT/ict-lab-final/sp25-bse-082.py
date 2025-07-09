name = input("Enter your name : ")
marks1 = int(input("Enter marks for Subject 1 : "))
marks2 = int(input("Enter marks for Subject 2 : "))
marks3 = int(input("Enter marks for Subject 3 : "))

average_marks = (marks1 + marks2 + marks3) / 3
status = ""
if (average_marks >= 40 ) {
status = "Pass"
} else {
    status = "Fail"
}

print("Student name : " , name)
print("Average Marks : ", average_marks)
print('Result : ', status)
