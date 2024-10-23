from typing import List

"""
Name: Abdikarim Jimale
Project:  simple text-based adventure
"""

class Room:
    """Represents a room in the game."""

    def __init__(self, name: str, description: str):
        """Initialize a Room object."""
        self.name = name
        self.description = description
        self.exits = {}
        self.items = []

    def add_exit(self, direction: str, room: 'Room') -> None:
        """Add an exit to another room."""
        self.exits[direction] = room

    def add_item(self, item: 'Item') -> None:
        """Add an item to the room."""
        self.items.append(item)

    def remove_item(self, item: 'Item') -> None:
        """Remove an item from the room."""
        if item in self.items:
            self.items.remove(item)
        else:
            print("This item isn't listed in the room.")

    def get_description(self) -> str:
        """Return a description of the room."""
        exits = ', '.join(self.exits.keys())
        items = ', '.join(item.name for item in self.items) or "None"
        return f"{self.name}\n{self.description}\nExits: {exits}\nItems in the room: {items}"


class Item:
    """Represents an item in the game."""

    def __init__(self, name: str, description: str):
        """Initialize an Item object."""
        self.name = name
        self.description = description  # Fixed typo (self.description)


class Player:
    """Represents the player in the game."""

    def __init__(self, name: str):
        """Initialize a Player object."""
        self.name = name
        self.inventory: List[Item] = []  # Changed to list
        self.current_room: Room = None

    def move(self, direction: str) -> None:
        """Move the player to a new room."""
        if direction in self.current_room.exits:
            if self.current_room.name == "Living Room" and direction == "exit": 
                if any(item.name.lower() == "key" for item in self.inventory): 
                    print("You use the key to exit the living room. You win the game.")
                    exit(0)
                else: 
                    print("The door is locked. you need a key to exit.")
                    return
            self.current_room = self.current_room.exits[direction]
            print(f"You move {direction} to the {self.current_room.name}.")
        else:
            print("You can't go that way.")

    def take_item(self, item_name: str) -> None:  # Changed item_name to an argument
        """Take an item from the current room."""
        for item in self.current_room.items:
            if item.name.lower() == item_name.lower():
                self.inventory.append(item)
                self.current_room.remove_item(item)
                print(f"You picked up the {item.name}.")
                return
        print(f"No {item_name} found here.")

    def drop_item(self, item_name: str) -> None:
        """Drop an item into the current room."""
        for item in self.inventory:
            if item.name.lower() == item_name.lower():
                self.current_room.add_item(item)
                self.inventory.remove(item)
                print(f"You dropped the {item.name}.")
                return
        print(f"You don't have {item_name} in your inventory.")

    def show_inventory(self) -> None:
        """Display the player's inventory."""
        if self.inventory:
            print(f"Inventory: {', '.join(item.name for item in self.inventory)}")
        else:
            print("Your inventory is empty.")


class Game:
    """Manages the game state and flow."""

    def __init__(self, player: Player, starting_room: Room):
        """Initialize a Game object."""
        self.player = player
        self.player.current_room = starting_room

    def play(self) -> None:
        print("You need to pick the key and go to the exit door that located at the kitcen to win the game.", 
              "\n", "*"*50 )
        print("Let's start the game!")
        while True:
            print(self.player.current_room.get_description())
            user_input = input("Enter a command (move, pick, inventory, drop, quit): ").lower().split()
            print("*"*50)
            if user_input[0] == "move" and len(user_input) > 1:
                self.player.move(user_input[1])
            elif user_input[0] == "pick" and len(user_input) > 1:
                self.player.take_item(user_input[1])  # Fixed method call
            elif user_input[0] == "inventory":
                self.player.show_inventory()
            elif user_input[0] == "drop" and len(user_input) > 1:
                self.player.drop_item(user_input[1])
            elif user_input[0] == "quit":  # Removed len(user_input) > 1 check
                print("Thanks for playing!")
                break
            else:
                print("Invalid command.")


def create_game_world() -> Game:
    """Create and set up the game world."""
    # Create rooms
    kitchen = Room("Kitchen", "A small kitchen with a refrigerator and a stove.")
    living_room = Room("Living Room", "A cozy living room with a fireplace.")
    bedroom = Room("Bedroom", "A comfortable bedroom with a large bed.")

    # Connect rooms
    kitchen.add_exit("east", living_room)
    living_room.add_exit("west", kitchen)
    living_room.add_exit("north", bedroom)
    living_room.add_exit("exit", None)
    bedroom.add_exit("south", living_room)

    # Create items
    key = Item("Key", "A small brass key.")
    book = Item("Book", "An old, leather-bound book.")

    # Add items to rooms
    kitchen.add_item(key)
    bedroom.add_item(book)

    # Create player and game
    player = Player("Alice")
    game = Game(player, kitchen)  # Start in the kitchen

    return game


def main() -> None:
    """Main function to set up and start the game."""
    game = create_game_world()
    game.play()


if __name__ == "__main__":
    main()
