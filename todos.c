#include <stdio.h>

// Function to write content to the file
void writeToFile(char filename[], int numLines);

// Function to read and display contents of the file
void readAndDisplayFile(char filename[]);

int main()
{
	char filename[] = "TODOs"; // Fixed filename

	// Get the number of lines to be entered
	int numLines;
	printf("Enter the number of Tasks: ");
	scanf("%d", &numLines);

	// Write content to the file
	writeToFile(filename, numLines);

	// Read and display contents of the file
	readAndDisplayFile(filename);

	return 0;
}

// Function to write content to the file
void writeToFile(char filename[], int numLines)
{
	FILE *filePointer;
	char content[100];

	// Open the file in writing mode
	filePointer = fopen(filename, "w");

	// Check if the file was opened successfully
	if (filePointer == NULL)
	{
		printf("Error opening file!\n");
		return; // Exit the function
	}

	// Consume the newline character left in the buffer
	getchar();

	// Get content from the user and write to the file
	printf("Enter tasks to make list:\n");

	for (int i = 0; i < numLines; ++i)
	{
		printf("Task %d: ", i + 1);
		fgets(content, sizeof(content), stdin);
		fprintf(filePointer, "%s", content);
	}

	// Close the file
	fclose(filePointer);

	printf("Tasks has been adde in the file '%s'.\n", filename);
}

// Function to read and display contents of the file
void readAndDisplayFile(char filename[])
{
	FILE *filePointer;
	char content[100];

	// Open the file in reading mode
	filePointer = fopen(filename, "r");

	// Check if the file was opened successfully
	if (filePointer == NULL)
	{
		printf("Error opening file for reading!\n");
		return; // Exit the function
	}

	// Display the contents of the file
	printf("\n\nTasks you have to complete:\n");

	while (fgets(content, sizeof(content), filePointer) != NULL)
	{
		printf("%s", content);
	}

	// Close the file
	fclose(filePointer);
}
