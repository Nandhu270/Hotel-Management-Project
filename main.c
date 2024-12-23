#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_USERS 100

typedef struct {
    int room_number;
    int is_available;
    char booked_by[50];
    char room_type[20];
} Room;

typedef struct {
    char username[50];
    char password[50];
} User;

Room rooms[MAX_ROOMS];
User users[MAX_USERS];

int num_rooms = 0;


char *room_types[] = {"Standard", "Deluxe", "Suite"};

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) 
    {
        rooms[i].room_number = i + 1;
        rooms[i].is_available = 1;
        strcpy(rooms[i].booked_by, "");
        if(i<50)
        {
            strcpy(rooms[i].room_type, "Standard");
        } 
        else if(i<80)
        {
            strcpy(rooms[i].room_type, "Deluxe");
        } 
        else 
        {
            strcpy(rooms[i].room_type, "Suite");
        }
        num_rooms++;
    }
}

void checkRoomAvailability() 
{    
    printf("\n1 --> Room available\n0 --> Room Booked\n");
    printf("\nAvailable Rooms:\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Room\t \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < (num_rooms/10) ; i++) 
    {   
        if(i<5)
        {
            printf("Standard-%d\t",i);
        }
        else if((4<i)&&(i<8))
        {
            printf("Deluxe-%d\t",i);
        }
        else if(i>7)
        {
            printf("Suite-%d\t\t",i);
        }
        
        for(int j=0;j<10;j++)
        {
            if (rooms[(i*10)+j].is_available) 
            {
                printf("1\t");
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    }
}

void makeBooking(char *username, int room_type) 
{
    for (int i = 0; i < num_rooms; i++) 
    {
        if (rooms[i].is_available && strcmp(rooms[i].room_type, room_types[room_type - 1]) == 0) 
        {
            rooms[i].is_available = 0;
            strcpy(rooms[i].booked_by, username);
            printf("Room %d (%s) has been booked for %s\n", rooms[i].room_number, rooms[i].room_type, username);
            return;
        }
    }
    printf("No available %s rooms.\n", room_types[room_type - 1]);
}

void cancelBooking(int room_number) 
{
    for (int i = 0; i < num_rooms; i++) 
    {
        if (rooms[i].room_number == room_number) 
        {
            rooms[i].is_available = 1;
            printf("Room %d for (%s) has been cancelled successfully\n", rooms[i].room_number, rooms[i].booked_by);
            strcpy(rooms[i].booked_by, "");
            return;
        }
    }
    printf("Room not found check your room no.\n");
}

void adminMenu() 
{
    int choice;
    printf("Admin Menu\n");
    printf("1. View all users\n");
    printf("2. Delete a user\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            printf("All users:\n");
            for (int i = 0; i < num_rooms; i++) 
            {   if(rooms[i].is_available==0)
                {   
                     printf("room %d(%s) - %s\n",rooms[i].room_number,rooms[i].room_type,rooms[i].booked_by);
                }
            }
            break;
        case 2:
            printf("Enter the username to delete: ");
            char del_username[50];
            scanf("%s", del_username);
            int found = 0;
            for (int i = 0; i < num_rooms; i++) 
            {
                if((rooms[i].is_available==0)&&(strcmp(rooms[i].booked_by,del_username)==0))
                {   
                  rooms[i].is_available = 1;
                  strcpy(rooms[i].booked_by, "");
                  printf("User %s deleted successfully.\n", del_username);
                  found = 1;
                  break;
                }
            }
            if (found==0) 
            {
                printf("User not found.\n");
            }
            break;
            default:printf("Invalid choice\n");
    }
}

void displayRoomTypes() {
    printf("Room Types:\n");
    printf("1. Standard\n");
    printf("2. Deluxe\n");
    printf("3. Suite\n");
}


int main() 
{
    int choice;
    char username[50];
    int room_type_choice;
    initializeRooms();
    printf("\n\t\t\t*** Welcome to Hotel Management System ***\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    while (1) 
    {
        printf("1. Check Room Availability\n");
        printf("2. Make Booking\n");
        printf("3. Cancel Booking\n");
        printf("4. Admin Menu\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                checkRoomAvailability();
                break;
            case 2:
                printf("Enter your username: ");
                scanf("%s", username);
                displayRoomTypes();
                printf("Enter room type number: ");
                scanf("%d", &room_type_choice);
                makeBooking(username, room_type_choice);
                break;
            case 3:
                printf("Enter room number to cancel booking: ");
                int room_num;
                scanf("%d", &room_num);
                cancelBooking(room_num);
                break;
            case 4:
                printf("Enter admin password: ");
                char admin_password[50];
                scanf("%s", admin_password);
                if (strcmp(admin_password, "admin") == 0) 
                {
                    adminMenu();
                } else {
                    printf("Incorrect password.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
