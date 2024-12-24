# Hotel Management System in C

This project is a **Hotel Management System** implemented in **C**, designed to manage room bookings, cancellations, and view room availability efficiently. It also includes an admin menu for managing bookings and users.

---

## Features

- **Room Management:**
  - Initialize rooms with different types: Standard, Deluxe, and Suite.
  - Check room availability with detailed status (booked/available).

- **Booking System:**
  - Book rooms for users with room type selection.
  - Cancel bookings by room number.

- **Admin Menu:**
  - View all booked rooms and associated user details.
  - Delete users and free up booked rooms.

- **Security:**
  - Admin menu protected by a password (`admin`).

---

## Technologies Used

- **C Programming Language**
- Console-based interface for interactive user input.

---

## How It Works

1. **Room Initialization:**
   - Rooms are categorized into three types:
     - **Standard:** Rooms 1–50.
     - **Deluxe:** Rooms 51–80.
     - **Suite:** Rooms 81–100.
   - All rooms are initially available.

2. **Booking Process:**
   - Users provide a username and select a room type.
   - The system assigns the first available room of the chosen type.

3. **Room Cancellation:**
   - Users can cancel their bookings by providing the room number.

4. **Admin Menu:**
   - Admin can view all booked rooms and the corresponding usernames.
   - Admin can delete users and free up booked rooms.

---

## Sample Output

*** Welcome to Hotel Management System ***
1. Check Room Availability
2. Make Booking
3. Cancel Booking
4. Admin Menu
5. Exit
Enter your choice: 1

Enter your username: JohnDoe
Room Types:
1. Standard
2. Deluxe
3. Suite
Enter room type number: 2
Room 51 (Deluxe) has been booked for JohnDoe
