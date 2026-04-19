/*
Name: EJJIET HAGAI
Registration Number: 25/U/BIO/01368/PD
*/

#include <stdio.h>

int main() {
    // Semester I Data: Credit Units
    int sem1_units[] = {4, 3, 3, 3, 3, 3, 2, 3};
    char *sem1_codes[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
                          "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};

    // Semester II Data: Credit Units
    int sem2_units[] = {4, 3, 3, 3, 3, 3, 3, 3};
    char *sem2_codes[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
                          "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};

    float sem1_scores[8], sem2_scores[8];
    float sem1_gp[8], sem2_gp[8];
    char sem1_grades[8], sem2_grades[8];

    float total_weighted_points_s1 = 0, total_units_s1 = 0;
    float total_weighted_points_s2 = 0, total_units_s2 = 0;

    // Input Semester I Scores
    for (int i = 0; i < 8; i++) {
        if (scanf("%f", &sem1_scores[i]) != 1) return 0;
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    // Input Semester II Scores
    for (int i = 0; i < 8; i++) {
        if (scanf("%f", &sem2_scores[i]) != 1) return 0;
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    // Processing Semester I
    for (int i = 0; i < 8; i++) {
        float score = sem1_scores[i];
        if (score >= 80) { sem1_gp[i] = 5; sem1_grades[i] = 'A'; }
        else if (score >= 70) { sem1_gp[i] = 4; sem1_grades[i] = 'B'; }
        else if (score >= 60) { sem1_gp[i] = 3; sem1_grades[i] = 'C'; }
        else if (score >= 50) { sem1_gp[i] = 2; sem1_grades[i] = 'D'; }
        else { sem1_gp[i] = 0; sem1_grades[i] = 'F'; }

        total_weighted_points_s1 += (sem1_gp[i] * sem1_units[i]);
        total_units_s1 += sem1_units[i];
    }

    // Processing Semester II
    for (int i = 0; i < 8; i++) {
        float score = sem2_scores[i];
        if (score >= 80) { sem2_gp[i] = 5; sem2_grades[i] = 'A'; }
        else if (score >= 70) { sem2_gp[i] = 4; sem2_grades[i] = 'B'; }
        else if (score >= 60) { sem2_gp[i] = 3; sem2_grades[i] = 'C'; }
        else if (score >= 50) { sem2_gp[i] = 2; sem2_grades[i] = 'D'; }
        else { sem2_gp[i] = 0; sem2_grades[i] = 'F'; }

        total_weighted_points_s2 += (sem2_gp[i] * sem2_units[i]);
        total_units_s2 += sem2_units[i];
    }

    float gpa1 = total_weighted_points_s1 / total_units_s1;
    float gpa2 = total_weighted_points_s2 / total_units_s2;
    float cgpa = (total_weighted_points_s1 + total_weighted_points_s2) / (total_units_s1 + total_units_s2);

    // Full Academic Report Output
    printf("\n--- ACADEMIC REPORT ---\n");
    printf("Course\t\tScore\tGrade\tGP\tUnit\tWeighted\n");
    for (int i = 0; i < 8; i++) {
        printf("%s\t%.1f\t%c\t%.1f\t%d\t%.1f\n", sem1_codes[i], sem1_scores[i], sem1_grades[i], sem1_gp[i], sem1_units[i], sem1_gp[i]*sem1_units[i]);
    }
    for (int i = 0; i < 8; i++) {
        printf("%s\t%.1f\t%c\t%.1f\t%d\t%.1f\n", sem2_codes[i], sem2_scores[i], sem2_grades[i], sem2_gp[i], sem2_units[i], sem2_gp[i]*sem2_units[i]);
    }

    // Required Summary Labels for Autograder
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    printf("Classification: ");
    if (cgpa >= 4.40) printf("First Class\n");
    else if (cgpa >= 3.60) printf("Second Class Upper\n");
    else if (cgpa >= 2.80) printf("Second Class Lower\n");
    else if (cgpa >= 2.00) printf("Pass\n");
    else printf("Fail\n");

    return 0;
}
