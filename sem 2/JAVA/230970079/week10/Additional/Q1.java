package Additional;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.Scanner;

public class Q1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read source directory name from the keyboard
        System.out.print("Enter source directory path: ");
        String sourceDirPath = scanner.nextLine();
        
        // Read destination directory name from the keyboard
        System.out.print("Enter destination directory path: ");
        String destinationDirPath = scanner.nextLine();
        
        try {
            // Copy files from source directory to destination directory
            copyFiles(sourceDirPath, destinationDirPath);
            System.out.println("Files copied successfully.");
        } catch (IOException e) {
            System.err.println("Error copying files: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }

    private static void copyFiles(String sourceDirPath, String destinationDirPath) throws IOException {
        File sourceDir = new File(sourceDirPath);
        File destinationDir = new File(destinationDirPath);
        
        // Check if source directory exists
        if (!sourceDir.exists() || !sourceDir.isDirectory()) {
            throw new IllegalArgumentException("Source directory does not exist or is not a directory.");
        }
        
        // Check if destination directory exists, if not, create it
        if (!destinationDir.exists()) {
            destinationDir.mkdirs();
        }
        
        // Iterate through files in source directory
        File[] files = sourceDir.listFiles();
        if (files != null) {
            for (File file : files) {
                // Copy each file to destination directory
                Path sourceFilePath = file.toPath();
                Path destinationFilePath = new File(destinationDir, file.getName()).toPath();
                Files.copy(sourceFilePath, destinationFilePath, StandardCopyOption.REPLACE_EXISTING);
            }
        }
    }
}

