allbooks = ["The Prophet" , "Treasured Writings of Khalil Gibran" , "The Silk Roads" , "Lost Islamic History" , "A Game of Thrones" , "The Hobbit" , "The Silmarillion" , "The Weary Generations" , "The Treasure Island" , "Anarchy"]
available_books = {}
borrowed_books = {}
#making dictionary from all available books
index = 1
for book in allbooks:
    available_books[index] = {"title" : book, "available" : True, "Serial" : index}
    index += 1

def show_avl_books():
   print("Serial            Title\n");
   for index, book in available_books.items():
        if book["available"]:  
             print("  " , book["Serial"] , book["title"])
   print('\n')

def borrow_book(num):
    if available_books[num]["available"]:
            available_books[num]["available"] = False
            
def return_book(r_book):
    for index, book in available_books.items():
        for key , value in book.items() : 
            if book["title"] == r_book:
                book["available"] = True
    

        

print("Welcome to Zafar Iqbal Library!")
print("What you want to do ?")

usrcmd = -1
while ( usrcmd != 0) :

    print("\n1.Borrow a book (one book at a time only)\n2.Return a book\n3.View available books\n4.See all books\n5.Exit\n")
    usrcmd = int(input("Enter relevant number : "))

    if usrcmd == 1:
        flag = True
        b_name = input("Enter your name : ")
        for name , title in borrowed_books.items():
           if name == b_name:
               print("You already had borrowed a book and can't borrow another one.")
               flag = False
        if flag:
            print("Following books are available : ")
            show_avl_books()
            book = int(input("What Book you want to borrow (enter serial) : "))
            borrow_book(book)
            borrowed_books.update({b_name : allbooks[book - 1]})
            print("You have borrowed" , allbooks[book - 1])
        
    if usrcmd == 2:
        r_name = input("Enter your name : ")
        if r_name in borrowed_books:
            bookname = borrowed_books[r_name]
            print("You had borrowed the following book : ")
            print(bookname)
            confirm = input("Press y to return the book , n to exit : ")
            if confirm == 'y':
                    return_book(bookname)
                    del borrowed_books[r_name]
                    print("You have successfully returned the book.")
            elif confirm == 'n':
                    break
            else :
                    print("Invalid Command")
        else : 
                print("You haven't borrowed any books.")

    if usrcmd == 3:
        print("Following books are available : ")
        show_avl_books()

    if usrcmd == 4:
        i = 1
        for book in allbooks:
            print(i , " ", book)
            i += 1;
    
    if usrcmd == 5:
        break;
        