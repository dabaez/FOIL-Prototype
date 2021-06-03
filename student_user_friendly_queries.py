from sklearn.tree import DecisionTreeClassifier
import time
import csv
from hle import * # our code

with open('data/student-mat.csv', 'r') as f:
    reader = csv.reader(f, delimiter=';')
    full_dataset = list(reader)

features = {
    'schoolGabrielP': 'boolean',
    'male': 'boolean',
    'age': 'numeric',
    'urbanHome': 'boolean',
    'bigFamily': 'boolean',
    'parentsTogether': 'boolean',
    'motherEducation': 'numeric',
    'fatherEducation': 'numeric',
    'travelTime': 'numeric',
    'studyTime': 'numeric',
    'pastFailures': 'numeric',
    'extraSchoolSupport': 'boolean',
    'extraFamilySupport': 'boolean',
    'payExtraClasses': 'boolean',
    'extacurricularActivties': 'boolean',
    'attendedNursery': 'boolean',
    'wantsHigherEducation': 'boolean',
    'internetAtHome': 'boolean',
    'inRomanticRel': 'boolean',
    'qualityFamilyRel': 'numeric',
    'amountFreetime': 'numeric',
    'qualitySocialLife': 'numeric',
    'alcoholWeek': 'numeric',
    'alcoholWeekend': 'numeric',
    'currentHealth': 'numeric',
    'numberAbsences': 'numeric',
    'gradePartial1': 'numeric',
    'gradePartial2': 'numeric',
}

class_names = ['goodFinalGrade', 'badFinalGrade']

feature_names = list(features.keys())
feature_types = list(features.values())

# because of binary features with values that are not 0 or 1.
feature_mapping = {
    'GP':1,
    'MS':0,
    'M':1,
    'F':0,
    'yes':1,
    'no':0,
    'U':1,
    'R':0,
    'GT3':1,
    'LE3':0,
    'T':1,
    'A':0,
}

def process_features_student(row):
    to_delete = [8, 9, 10,11]
    cpy = []
    for i in range(len(row)):
        if i not in to_delete:
            value = row[i]
            if value in feature_mapping:
                cpy.append(feature_mapping[value])
            else:
                cpy.append(value)
    assert len(cpy) == len(feature_names)
    return cpy

def process_class(val):
    if float(val) >= 10: # good grade is a grade in  [10, 20]. Bad grade is [0, 10)
        return 0
    else:
        return 1

dataset = full_dataset[1:]
X = [ process_features_student(data[:-1]) for data in dataset]
y = [ process_class(data[-1]) for data in dataset]

student_clf = DecisionTreeClassifier(max_leaf_nodes=400, random_state=0)
student_clf.fit(X, y)

q1 = 'exists student, student.studyTime <= 2 and student.gradePartial1 <= 8 and goodFinalGrade(student)'
q2 = 'exists student, student.studyTime <= 4 and student.gradePartial1 <= 6 and goodFinalGrade(student)'
q3 = ('exists st1, full(st1) and not goodFinalGrade(st1)')
q4 = 'for every student, student.studyTime > 3 and student.gradePartial1 > 16 implies goodFinalGrade(student)'

q5 = ('exists st1, exists st2, st1.studyTime > 2 and st2.studyTime <= 3'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q6 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' implies not goodFinalGrade(student)')

q7 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 8 and st2.gradePartial1 > 15'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q8 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 17'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q9 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 17'
        ' and st1.male=true and st2.male=false'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q10 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 17'
        ' and st1.gradePartial2 <= 12 and st2.gradePartial2 > 12'
        ' and st1.male=true and st2.male=false'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q11 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 17'
        ' and st1.gradePartial2 <= 12 and st2.gradePartial2 > 6'
        ' and st1.male=true and st2.male=false'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q12 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 17'
        ' and st1.gradePartial2 <= 12 and st2.gradePartial2 > 11'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q13 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 14'
        ' and st1.gradePartial2 <= 14 and st2.gradePartial2 > 8'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q14 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 14'
        ' and st1.male=false and st2.male=true'
        ' and st1.gradePartial2 <= 10 and st2.gradePartial2 > 10'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q15 = ('exists st1, exists st2, st1.studyTime <= 2 and st2.studyTime > 3'
        ' and st1.gradePartial1 <= 6 and st2.gradePartial1 > 14'
        ' and st1.gradePartial2 <= 10 and st2.gradePartial2 > 10'
        ' and goodFinalGrade(st1) and full(st2) and not goodFinalGrade(st2)')

q16 = ('exists student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.gradePartial2 <= 6 and goodFinalGrade(student)')

q17 = ('exists student, student.gradePartial2 <= 8 and goodFinalGrade(student)')

q18 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.numberAbsences <= 1'
        ' implies not goodFinalGrade(student)')


q19 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.numberAbsences <= 1 and student.gradePartial1 <= 6'
        ' implies not goodFinalGrade(student)')

q20 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.numberAbsences <= 1 and student.gradePartial1 <= 6'
        ' and student.gradePartial2 <= 9'
        ' implies not goodFinalGrade(student)')

q21 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.numberAbsences <= 1 and student.gradePartial1 <= 6'
        ' and student.gradePartial2 <= 9'
        ' implies not goodFinalGrade(student)')

q22 = ('for every student, student.alcoholWeekend > 3 and student.alcoholWeek > 3'
        ' and student.numberAbsences > 1 and student.gradePartial1 <= 6'
        ' and student.gradePartial2 <= 9'
        ' implies not goodFinalGrade(student)')

queries = [q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20, q21, q22]
for iq, query in enumerate(queries):
    t1 = time.perf_counter()
    answer = high_level_single(student_clf, feature_names, feature_types, class_names, query, debug)[:-1]
    delta = time.perf_counter() - t1
    print(f'q{iq+1}: answer={answer}, time={delta}')
