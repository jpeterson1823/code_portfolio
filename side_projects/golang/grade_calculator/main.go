package main

import (
	"fmt"
	"grade_calculator/course"
)

func main() {
	fmt.Println("Starting...")

	cs := course.NewCourse("Example Course")
	cs.AddGradeSections([]course.GradeSection{
		*course.NewGradeSectionPercent("Exam #1 ", 71.0, 20.0),
		*course.NewGradeSectionPercent("Exam #2 ", 62.0, 20.0),
		*course.NewGradeSectionPercent("Exam #3 ", 79.0, 20.0),
		*course.NewGradeSectionPercent("Final   ", 73.0, 30.0),
		*course.NewGradeSectionPercent("Homework", 50.0, 10.0),
	})
	cs.Println()

	fmt.Println("DONE!")
}
