#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

class Student {
private:
    string name;
    string id;
    double GPA;
public:
    Student() {
        id = "";
        GPA = 0;
        name = "";
    };
    Student(string sName, string sId, double sGpa) {
        name = sName;
        id = sId;
        GPA = sGpa;
    };
    string getID() const {
        return id;
    };

    double getGPA() const {
        return GPA;
    };

    string getName() const {
        return name;
    };
    
    bool operator<(const Student& other) const {
        return name < other.name;
    }
    friend istream& operator>>(istream& input, Student& student) {
        input.ignore();
        getline(input, student.name); 
        getline(input, student.id);
        input >> student.GPA;
        input.ignore();
        return input;
    };
};

template <typename T>
void insertionSortByGPA(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Insertion Sort" << endl;
    for (int i = 1, j; i < n; i++) {
        T temp = arr[i];
        for (j = i; j > 0 && temp.getGPA()>arr[j - 1].getGPA(); j--) {
            numberOfComparisons++;
            arr[j] = arr[j - 1];
        }
        numberOfComparisons++;
        arr[j] = temp;
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of insertion sort is : " << numberOfComparisons << endl;
}


template <typename T>
void insertionSortByName(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Insertion Sort" << endl;
    for (int i = 1, j; i < n; i++) {
        T temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--) {
            numberOfComparisons++;
            arr[j] = arr[j - 1];
        }
        numberOfComparisons++;
        arr[j] = temp;
    }

    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of insertion sort is : " << numberOfComparisons << endl;
}


template <typename T>
void selectionSortByGpa(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Selection Sort" << endl;
    for (int index = 0, largest = index; index < n - 1; index++) {
        largest = index;
        for (int j = index + 1; j < n; j++) {
            if (arr[j].getGPA() > arr[largest].getGPA()) {
                largest = j;
            }
            numberOfComparisons++;
        }
        if (largest != index) {
            swap(arr[index], arr[largest]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of selection sort is : " << numberOfComparisons << endl;
}


template <typename T>
void selectionSortByName(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Selection Sort" << endl;
    for (int index = 0, largest = index; index < n - 1; index++) {
        largest = index;
        for (int j = index + 1; j < n; j++) {
            if (arr[j] < arr[largest]) {
                largest = j;
            }
            numberOfComparisons++;
        }
        if (largest != index) {
            swap(arr[index], arr[largest]);
        }
    }
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of selection sort is : " << numberOfComparisons << endl;
}


template <typename T>
void bubbleSortByGPA(T arr[], int n, ofstream& outFile) {
    int flag = 0;
    int numberOfComparisons = 0;
    outFile << "Algorithm: Bubble Sort " << endl;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j+1].getGPA() > arr[j].getGPA()) {
                swap(arr[j+1], arr[j]);
                flag = 1;
            }
            numberOfComparisons++;
        }
        if(flag == 0){   
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of bubble sort is : " << numberOfComparisons << endl;
}


template <typename T>
void bubbleSortByName(T arr[], int n, ofstream& outFile) {
    int flag = 0;
    int numberOfComparisons = 0;
    outFile << "Algorithm: Bubble Sort" << endl;
    for (int i = n - 1; i > 0; i--) {
        numberOfComparisons++;
        for (int j = 0; j < i; j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);
                flag = 1;
            }
            numberOfComparisons++;
        }
        if(flag == 0){   
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of bubble sort is : " << numberOfComparisons << endl;
}


template <typename T>
void shellSortByGPA(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Shell Sort " << endl;
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for(j = i; j >= gap && temp.getGPA() > arr[j - gap].getGPA(); j -= gap) {
                numberOfComparisons++;
                arr[j] = arr[j - gap];
            }
            numberOfComparisons++;
            arr[j] = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of shell sort is : " << numberOfComparisons << endl;
}


template <typename T>
void shellSortByName(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: Shell Sort" << endl;

    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for(j = i; j >= gap && temp < arr[j - gap]; j -= gap) {
                numberOfComparisons++;
                arr[j] = arr[j - gap];
            }
            numberOfComparisons++;
            arr[j] = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        outFile << arr[i].getName() << " " << arr[i].getID() << " " << arr[i].getGPA() << endl;
    }
    outFile << "Total comparisons of shell sort is : " << numberOfComparisons << endl;
}


template <typename T>
int mergeByGPA(T arr[], int left, int middle, int right) {
    int numberOfComparisons = 0;
    int firstPartSize = middle - left + 1;
    int secondPartSize = right - middle;

    
    T* firstPartArray = new T[firstPartSize];
    T* secondPartArray = new T[secondPartSize];

    
    for (int i = 0; i < firstPartSize; i++) {
        firstPartArray[i] = arr[left + i];
    }
    for (int j = 0; j < secondPartSize; j++) {
        secondPartArray[j] = arr[middle + 1 + j];
    }

    
    int firstIndexOfFirstPart = 0;
    int firstIndexOfSecondPart = 0;
    int firstIndexOfFullArray = left;

    while (firstIndexOfFirstPart < firstPartSize && firstIndexOfSecondPart < secondPartSize) {
        if (firstPartArray[firstIndexOfFirstPart].getGPA() > secondPartArray[firstIndexOfSecondPart].getGPA()) {
            arr[firstIndexOfFullArray++] = firstPartArray[firstIndexOfFirstPart++];
        } else {
            arr[firstIndexOfFullArray++] = secondPartArray[firstIndexOfSecondPart++];
        }
        numberOfComparisons++;
    }

    
    while (firstIndexOfFirstPart < firstPartSize) {
        arr[firstIndexOfFullArray++] = firstPartArray[firstIndexOfFirstPart++];
        numberOfComparisons++;
    }

    
    while (firstIndexOfSecondPart < secondPartSize) {
        arr[firstIndexOfFullArray++] = secondPartArray[firstIndexOfSecondPart++];
        numberOfComparisons++;
    }

    
    delete[] firstPartArray;
    delete[] secondPartArray;
    return numberOfComparisons;
}



template <typename T>
int mergeSortByGPA(T arr[], int left, int right ) {
    int totalComparisons = 0;
    if (left >= right) {
        return totalComparisons;
    }
    int middle = left + (right - left) / 2;
    totalComparisons += mergeSortByGPA(arr, left, middle);
    totalComparisons += mergeSortByGPA(arr, middle + 1, right);
    totalComparisons += mergeByGPA(arr, left, middle, right);
    return totalComparisons;
}


template <typename T>
int mergeByName(T arr[], int left, int middle, int right) {
    int numberOfComparisons = 0;
    int firstPartSize = middle - left + 1;
    int secondPartSize = right - middle;

    
    T* firstPartArray = new T[firstPartSize];
    T* secondPartArray = new T[secondPartSize];

    
    for (int i = 0; i < firstPartSize; i++) {
        firstPartArray[i] = arr[left + i];
    }
    for (int j = 0; j < secondPartSize; j++) {
        secondPartArray[j] = arr[middle + 1 + j];
    }

    
    int firstIndexOfFirstPart = 0;
    int firstIndexOfSecondPart = 0;
    int firstIndexOfFullArray = left;

    while (firstIndexOfFirstPart < firstPartSize && firstIndexOfSecondPart < secondPartSize) {
        if (firstPartArray[firstIndexOfFirstPart] < secondPartArray[firstIndexOfSecondPart]) {
            arr[firstIndexOfFullArray++] = firstPartArray[firstIndexOfFirstPart++];
        } else {
            arr[firstIndexOfFullArray++] = secondPartArray[firstIndexOfSecondPart++];
        }
        numberOfComparisons++;
    }

    
    while (firstIndexOfFirstPart < firstPartSize) {
        arr[firstIndexOfFullArray++] = firstPartArray[firstIndexOfFirstPart++];
        numberOfComparisons++;
    }

    
    while (firstIndexOfSecondPart < secondPartSize) {
        arr[firstIndexOfFullArray++] = secondPartArray[firstIndexOfSecondPart++];
        numberOfComparisons++;
    }

    
    delete[] firstPartArray;
    delete[] secondPartArray;
    return numberOfComparisons;
}



template <typename T>
int mergeSortByName(T arr[], int left, int right) {
    int totalComparisons = 0;
    if (left >= right) {
        return totalComparisons;
    }
    int middle = left + (right - left) / 2;
    totalComparisons+= mergeSortByName(arr, left, middle);
    totalComparisons+=mergeSortByName(arr, middle + 1, right);
    totalComparisons+=mergeByName(arr, left, middle, right);
    return totalComparisons;
}


template <typename T>
int partitionByGPA(T arr[], int left, int right) {
    T pivot = arr[left];
    int i = left;
    for (int j = i + 1; j <= right; j++) {
        if (arr[j].getGPA() > pivot.getGPA()) {  
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[left]);
    return i;
}

template <typename T>
int quickSortByGPA(T arr[], int left, int right) {
    int totalComparisons = 0;
    if (left >= right) {
        return totalComparisons;
    }
    int middle = partitionByGPA(arr, left, right);
    totalComparisons += (right - left);
    totalComparisons += quickSortByGPA(arr, left, middle - 1);
    totalComparisons += quickSortByGPA(arr, middle + 1, right);
    return totalComparisons;
}


template <typename T>
int partitionByName(T arr[], int left, int right) {
    T pivot = arr[left];
    int i = left;
    for (int j = i + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[left]);
    return i;
}

template <typename T>
int quickSortByName(T arr[], int left, int right) {
    int totalComparisons = 0;
    if (left >= right) {
        return totalComparisons;
    }
    int middle = partitionByName(arr, left, right);
    totalComparisons += (right - left);
    totalComparisons += quickSortByName(arr, left, middle - 1);
    totalComparisons += quickSortByName(arr, middle + 1, right);
    return totalComparisons;
}

template <typename T>
void countingSortByGPA(T arr[], int n, ofstream& outFile) {
    int numberOfComparisons = 0;
    outFile << "Algorithm: count Sort " << endl;

    int maxGPA = static_cast<int>(arr[0].getGPA());
    for (int i = 1; i < n; i++) {
        if (static_cast<int>(arr[i].getGPA()) > maxGPA) {
            maxGPA = static_cast<int>(arr[i].getGPA());
        }
    }

    int count[5] = {0};
    for (int i = 0; i < n; i++) {
        count[static_cast<int>(arr[i].getGPA())]++;
    }


    for (int i = 1; i <= maxGPA; i++) {
        count[i] += count[i - 1];
    }


    T output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[static_cast<int>(arr[i].getGPA())] - 1] = arr[i];
        count[static_cast<int>(arr[i].getGPA())]--;
    }

    for (int i = n-1; i >= 0; i--) {
        outFile << output[i].getName() << " " << output[i].getID() << " " << static_cast<int>(output[i].getGPA()) << endl;
    }
    outFile << "Total comparisons of count sort is : " << numberOfComparisons << endl;
}

template<typename T>
void copyArray(const T source[], T destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}


int main() {
    ifstream datafile("students.txt");
    if (!datafile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    int numStudents;
    //extraction operator
    datafile >> numStudents;
    datafile.ignore();
    Student students[numStudents];
    Student unsortedStudents[numStudents];
    for (int i = 0; i < numStudents; i++) {
        datafile >> students[i];
        unsortedStudents[i] =  students[i];
    }
    datafile.close();

    ofstream sortedByGPAFile("SortedByGPA.txt");
    if (!sortedByGPAFile.is_open()) {
        cout << "Error opening SortedByGPA.txt" << endl;
        return 1;
    }


    auto start = chrono::high_resolution_clock::now();
    insertionSortByGPA(students, numStudents, sortedByGPAFile);
    auto end = chrono::high_resolution_clock::now();
    chrono::microseconds elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Insertion Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);


     start = chrono::high_resolution_clock::now();
    insertionSortByGPA(students, numStudents, sortedByGPAFile);
     end = chrono::high_resolution_clock::now();
     elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Insertion Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    selectionSortByGpa(students, numStudents, sortedByGPAFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Selection Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    bubbleSortByGPA(students, numStudents, sortedByGPAFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Bubble Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    shellSortByGPA(students, numStudents, sortedByGPAFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Shell Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    countingSortByGPA(students, numStudents, sortedByGPAFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Count Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    int numberOfMergeSortComparisonsByGpa = mergeSortByGPA(students, 0, numStudents - 1);
    sortedByGPAFile << "Algorithm: Merge Sort" << endl;
    for (int i = 0; i < numStudents; i++) {
        sortedByGPAFile  << students[i].getName() << " " << students[i].getID() << " " << students[i].getGPA() << endl;
    }
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Total comparisons of merge sort is : " << numberOfMergeSortComparisonsByGpa << endl;
    sortedByGPAFile << "Merge Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    int numberOfQuickSortComparisonsByGpa = quickSortByGPA(students, 0, numStudents - 1);
    sortedByGPAFile << "Algorithm: Quick Sort" << endl;
    for (int i = 0; i < numStudents; i++) {
        sortedByGPAFile  << students[i].getName() << " " << students[i].getID() << " " << students[i].getGPA() << endl;
    }
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByGPAFile << "Total comparisons of quick sort is : " << numberOfQuickSortComparisonsByGpa << endl;
    sortedByGPAFile << "Quick Sort by GPA took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByGPAFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);





    ifstream fileInput1("SortedByGPA.txt");
    vector<string> lines1;
    string line1;
    // Read all lines into a vector
    while (getline(fileInput1, line1)) {
        lines1.push_back(line1);
    }

    fileInput1.close();
    // Check if there are at least 8 lines to delete
    if (lines1.size() > 8) {
        lines1.erase(lines1.begin(), lines1.begin() + 8);
    }
    // Write remaining lines back to the file
    ofstream fileOutput1("SortedByGPA.txt");
    for (const auto& ln : lines1) {
        fileOutput1 << ln << endl;
    }


    sortedByGPAFile.close();

    ofstream sortedByNameFile("SortedByName.txt");
    if (!sortedByNameFile.is_open()) {
        cout << "Error opening SortedByName.txt" << endl;
        return 1;
    }

    start = chrono::high_resolution_clock::now();
    insertionSortByName(students, numStudents, sortedByNameFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Insertion Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);



    start = chrono::high_resolution_clock::now();
    insertionSortByName(students, numStudents, sortedByNameFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Insertion Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);

    start = chrono::high_resolution_clock::now();
    selectionSortByName(students, numStudents, sortedByNameFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Selection Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);
    
    start = chrono::high_resolution_clock::now();
    bubbleSortByName(students, numStudents, sortedByNameFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Bubble Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);
    
    start = chrono::high_resolution_clock::now();
    shellSortByName(students, numStudents, sortedByNameFile);
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Shell Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);
    
    start = chrono::high_resolution_clock::now();
    int numberOfMergeSortComparisonsByName = mergeSortByName(students, 0, numStudents - 1);
    sortedByNameFile << "Algorithm: Merge Sort" << endl;
    for (int i = 0; i < numStudents; i++) {
        sortedByNameFile  << students[i].getName() << " " << students[i].getID() << " " << students[i].getGPA() << endl;
    }
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Total comparisons of merge sort is : " << numberOfMergeSortComparisonsByName << endl;
    sortedByNameFile << "Merge Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);
    
    start = chrono::high_resolution_clock::now();
    int numberOfQuickSortComparisonsByName = quickSortByName(students, 0, numStudents - 1);
    sortedByNameFile << "Algorithm: Quick Sort" << endl;
    for (int i = 0; i < numStudents; i++) {
        sortedByNameFile  << students[i].getName() << " " << students[i].getID() << " " << students[i].getGPA() << endl;
    }
    end = chrono::high_resolution_clock::now();
    elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start);
    sortedByNameFile << "Total comparisons of quick sort is : " << numberOfQuickSortComparisonsByName << endl;
    sortedByNameFile << "Quick Sort by Name took: " << elapsed_microseconds.count() << " microseconds" << endl;
    sortedByNameFile << "--------------------------------------------" << endl;
    copyArray(unsortedStudents, students, numStudents);





    ifstream fileInput("sortedByName.txt");
    vector<string> lines;
    string line;
    // Read all lines into a vector
    while (getline(fileInput, line)) {
        lines.push_back(line);
    }
    fileInput.close();

    // Check if there are at least 8 lines to delete
    if (lines.size() > 8) {
        lines.erase(lines.begin(), lines.begin() + 8);
    }

    // Write remaining lines back to the file
    ofstream fileOutput("sortedByName.txt");
    for (const auto& ln : lines) {
        fileOutput << ln << endl;
    }


    sortedByNameFile.close();

    return 0;

}




