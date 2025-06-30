# Menu and Prices
items = ['Burger', 'Fries', 'Tea', 'Coffee', 'Sandwich']
prices = [150, 100, 30, 50, 120]

# Show menu
print("\n--- Menu ---")
for i in range(len(items)):
    print(f"{items[i]} - Rs.{prices[i]}")

# Customer details
name = input("\nEnter your name: ")
num_items = input("How many items do you want to purchase? ")

while not num_items.isdigit():
    print("Invalid input. Please enter a number.")
    num_items = input("How many items do you want to purchase? ")

num_items = int(num_items)

# Order input and cost calculation
total_cost = 0
ordered_items = []
i = 0
while i < num_items:
    item = input(f"Enter item {i + 1}: ").capitalize()
    if item in items:
        index = items.index(item)
        total_cost += prices[index]
        ordered_items.append(item)
        i += 1
    else:
        print("Item not available. Please choose again.")
        continue  # transfer statement

# Apply discount based on total
if total_cost < 200:
    discount = 0
elif 200 <= total_cost <= 500:
    discount = total_cost * 0.10
else:
    discount = total_cost * 0.20

final_amount = total_cost - discount

# Function to print bill
def print_bill(cust_name, total_items, cost_before_discount, discount_amount, final_amount):
    print("\n===== Final Bill =====")
    print("Customer Name:", cust_name)
    print("Total Items:", total_items)
    print(f"Total Cost Before Discount: Rs.{cost_before_discount}")
    print(f"Discount Applied: Rs.{discount_amount}")
    print(f"Final Amount to Pay: Rs.{final_amount}")

# Show final bill
print_bill(name, num_items, total_cost, discount, final_amount)
