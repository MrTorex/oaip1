
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct student
{
    unsigned id;
    string surname;
    unsigned group_number;
    unsigned physics;
    unsigned math;
    unsigned inf;
    double average;
};

bool compare_by_id(const student& student1, const student& student2)
{
    return student1.id < student2.id;
}

bool compare_by_surname(const student& student1, const student& student2)
{
    return student1.surname < student2.surname;
}

bool compare_by_average(const student& student1, const student& student2)
{
    return student1.average < student2.average;
}

bool compare_by_group_number(const student& student1, const student& student2)
{
    return student1.group_number < student2.group_number;
}

void read_file(unsigned& students_count, vector<student>& students_array)
{
    ifstream file("students.txt");

    string buffer;

    getline(file, buffer);

    students_count = stoi(buffer);

    for (int i = 0; i < students_count; i++)
    {
        student push_back_student;

        getline(file, buffer, ' ');
        push_back_student.id = stoi(buffer);

        getline(file, buffer, ' ');
        push_back_student.surname = buffer;

        getline(file, buffer, ' ');
        push_back_student.group_number = stoi(buffer);

        getline(file, buffer, ' ');
        push_back_student.physics = stoi(buffer);

        getline(file, buffer, ' ');
        push_back_student.math = stoi(buffer);

        getline(file, buffer, ' ');
        push_back_student.inf = stoi(buffer);

        getline(file, buffer, '\n');
        push_back_student.average = stod(buffer);

        students_array.push_back(push_back_student);
    }

    file.close();
}

void rewrite_file(const unsigned& students_count, const vector<student>& students_array)
{
    ofstream file("temp.txt");

    file << students_count << '\n';

    for (int i = 0; i < students_count; i++)
    {
        file << students_array[i].id << ' ';

        file << students_array[i].surname << ' ';

        file << students_array[i].group_number << ' ';

        file << students_array[i].physics << ' ';

        file << students_array[i].math << ' ';

        file << students_array[i].inf << ' ';

        file << students_array[i].average << '\n';
    }

    file.close();

    remove("students.txt");

    rename("temp.txt", "students.txt");
}

void create_new_file(unsigned& students_count, vector<student>& students_array)
{
    ofstream file("temp.txt");

    student test_student{ 1, "Ivanov", 324401, 1, 1, 1, 1 };

    students_count = 1;

    students_array.clear();

    students_array.push_back(test_student);

    file << students_count << '\n' << test_student.id << " " << test_student.surname << " " << test_student.group_number << " ";
    file << test_student.physics << " " << test_student.math << " " << test_student.inf << " " << test_student.average << '\n';

    file.close();

    remove("students.txt");

    rename("temp.txt", "students.txt");
}

void print_file(const unsigned& students_count, const vector<student>& students_array)
{
    system("cls");

    cout << "--------------------------------StudentsDatabase v. 0.0.1--------------------------------\n\n";
    cout << "ID:" << setw(12) << "Surname" << setw(20) << "Group number:" << setw(12) << "Physics:" << setw(12) << "Math:" << setw(12) << "Inf:" << setw(20) << "Average:\n\n";

    for (int i = 0; i < students_count; i++)
    {
        cout << students_array[i].id << setw(15) << students_array[i].surname << setw(18) << students_array[i].group_number << setw(13);
        cout << students_array[i].physics << setw(13) << students_array[i].math << setw(12) << students_array[i].inf << setw(15) << students_array[i].average << '\n';
    }
    cout << "\n-----------------------------------------------------------------------------------------\n";
}

void add_student(unsigned& students_count, vector<student>& students_array)
{
    string local_choice;

    do
    {
        system("cls");

        students_count++;

        student student_to_add;

        student_to_add.id = students_count;

        cout << "Enter surname: ";
        cin >> student_to_add.surname;

        cout << "\nEnter group number: ";
        cin >> student_to_add.group_number;

        cout << "\nEnter physics mark: ";
        cin >> student_to_add.physics;

        cout << "\nEnter maths mark: ";
        cin >> student_to_add.math;

        cout << "\nEnter informatics mark: ";
        cin >> student_to_add.inf;

        student_to_add.average = (student_to_add.physics + student_to_add.math + student_to_add.inf) / 3.;

        students_array.push_back(student_to_add);

        cout << "\nDo you want to add one more student (y/n)? ";
        cin >> local_choice;
    } while (local_choice != "n");

    rewrite_file(students_count, students_array);
}

void delete_student(unsigned& students_count, vector<student>& students_array)
{
    unsigned student_to_delete_id, student_to_delete_number;

    cout << "\nEnter student to delete ID: ";
    cin >> student_to_delete_id;

    for (int i = 0; i < students_count; i++)
    {
        if (students_array[i].id == student_to_delete_id)
        {
            student_to_delete_number = i;
            break;
        }
    }

    students_count--;

    if (students_count == 0)
        create_new_file(students_count, students_array);
    else
    {
        students_array.erase(students_array.begin() + student_to_delete_number);

        for (int i = 0; i < students_count; i++)
        {
	        if (students_array[i].id > student_to_delete_id)
                students_array[i].id--;
        }

        rewrite_file(students_count, students_array);
    }
}

void edit_student(const unsigned& students_count, vector<student>& students_array)
{
    unsigned student_to_edit_id;

    cout << "\nEnter student to edit ID: ";
    cin >> student_to_edit_id;

    for (int i = 0; i < students_count; i++)
    {
        if (students_array[i].id = student_to_edit_id)
        {
            student_to_edit_id = i;
            break;
        }
    }

    cout << "\nEnter surname: ";
    cin >> students_array[student_to_edit_id].surname;

    cout << "\nEnter group number: ";
    cin >> students_array[student_to_edit_id].group_number;

    cout << "\nEnter physics mark: ";
    cin >> students_array[student_to_edit_id].physics;

    cout << "\nEnter maths mark: ";
    cin >> students_array[student_to_edit_id].math;

    cout << "\nEnter informatics mark: ";
    cin >> students_array[student_to_edit_id].inf;

    students_array[student_to_edit_id].average = (students_array[student_to_edit_id].physics + students_array[student_to_edit_id].math + students_array[student_to_edit_id].inf) / 3.;

    rewrite_file(students_count, students_array);
}

void sort_students(const unsigned& students_count, vector<student>& students_array)
{
    unsigned sort_type;

    cout << "\nHow do you want to sort students? (by surname - 1, by group number - 2, by average mark - 3, by ID - 4): ";
    cin >> sort_type;

    switch (sort_type)
    {
		case 1:
            sort(students_array.begin(), students_array.end(), compare_by_surname);
            break;
        case 2:
            sort(students_array.begin(), students_array.end(), compare_by_group_number);
            break;
        case 3:
            sort(students_array.begin(), students_array.end(), compare_by_average);
            break;
        case 4:
            sort(students_array.begin(), students_array.end(), compare_by_id);
            break;
        default:
            break;
    }

    rewrite_file(students_count, students_array);
}

void personal_task(const unsigned& students_count, const vector<student>& students_array)
{
    unsigned group_number;

    vector<student> group;

    cout << "\nEnter group number: ";
    cin >> group_number;

    for (int i = 0; i < students_count; i++)
    {
	    if (students_array[i].physics >= 9 && students_array[i].math >= 9 && students_array[i].inf >= 9 && students_array[i].group_number == group_number)
            group.push_back(students_array[i]);
    }

    cout << "\nExcellent students: ";

    for (int i = 0; i < group.size(); i++)
    	cout << group[i].surname << " ";

    cout << "\n";
    system("pause");
}

void navigation(unsigned& students_count, vector<student>& students_array, unsigned& choice)
{
    cout << "Add new student - 1\n";
    cout << "Delete existing student - 2\n";
    cout << "Sort students - 3\n";
    cout << "Edit student - 4\n";
    cout << "Personal task - 5\n";
    cout << "Exit - any other\n";
    cin >> choice;

    switch (choice)
    {
		case 1:
            add_student(students_count, students_array);
    		break;
		case 2:
			delete_student(students_count, students_array);
			break;
		case 3:
			sort_students(students_count, students_array);
			break;
        case 4:
            edit_student(students_count, students_array);
            break;
        case 5:
            personal_task(students_count, students_array);
            break;
		default:
			system("cls");
			cout << "Have a good day!" << '\n';
			break;
    }
}

int main()
{
    vector<student> students_array;

    unsigned students_count, choice = 0;

    cout << "Work with current file (1) or create new one (2)? ";
    cin >> choice;

    if (choice == 1)
    {
        read_file(students_count, students_array);
        do 
        {
            print_file(students_count, students_array);
            navigation(students_count, students_array, choice);
        } while (choice < 6);
    }

    if (choice == 2)
    {
        create_new_file(students_count, students_array);
        read_file(students_count, students_array);
        do
        {
            print_file(students_count, students_array);
            navigation(students_count, students_array, choice);
        } while (choice < 6);
    }

    return 0;
}
