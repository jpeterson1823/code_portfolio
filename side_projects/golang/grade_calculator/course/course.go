package course

import "fmt"

type Course struct {
	name     string
	sections []GradeSection
}

func NewCourse(name string) *Course {
	return &Course{name, []GradeSection{}}
}

func (cs *Course) AddGradeSections(gradeSections []GradeSection) {
	cs.sections = append(cs.sections, gradeSections...)
}

func (cs *Course) AddGradeSection(gs GradeSection) {
	cs.sections = append(cs.sections, gs)
}

func (cs Course) CalcFinalGradePercent() float64 {
	finalGrade := 0.0
	for _, gs := range cs.sections {
		finalGrade += gs.CalcContribution()
	}
	return finalGrade * 100.0
}

func (cs Course) Println() {
	finalGrade := cs.CalcFinalGradePercent()
	fmt.Printf("%s : %v%%\n", cs.name, finalGrade)
	for _, gs := range cs.sections {
		fmt.Printf("    [%v%%] %s: %g%%\n", gs.percentWorth*100, gs.name, gs.CalcGradePercent())
	}
}
