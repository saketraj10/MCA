<!DOCTYPE html> 
<html> 
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style> 
        table { 
            width: 100%; 
            border-collapse: collapse; 
        }
        table, td, th { 
            border: 1px solid black; 
            padding: 5px; 
        } 
        th {
            text-align: left;
        } 
    </style> 
</head> 
<body> 
    <h1>Employee Details</h1> 
    <?php

    // Define employee details
    $employees = array(
      array("name" => "Nidhi", "age" => 30, "salary" => 5000),
      array("name" => "Kaushik", "age" => 25, "salary" => 4000),
      array("name" => "Rohan", "age" => 35, "salary" => 6000)
    );
    // Convert to JSON string
    $employees_json = json_encode($employees);
    // Open file for writing
    $file = fopen("employees.json", "w");
    // Write JSON string to file
    fwrite($file, $employees_json);
    // Close file
    fclose($file);

    // Read the employee details in JSON format
    $employees_json = file_get_contents('employees.json');

    // Convert JSON string to array
    $employees_array = json_decode($employees_json, true);

    // Display the employee details in a table
    echo "<table border='1'>";
    echo "<tr>
            <th>Name</th>
            <th>Age</th>
            <th>Salary</th>
        </tr>";
    foreach($employees_array as $employee) 
    {
        echo "<tr>
            <td>".$employee['name']."</td>
            <td>".$employee['age']."</td>
            <td>".$employee['salary']."</td>
        </tr>";
    }
    echo "</table>";
    ?>
</body> 
</html>