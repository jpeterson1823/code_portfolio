package course

type GradeSection struct {
	name                      string
	earnedPoints, totalPoints float64
	percentWorth              float64
}

// GradeSection "Constructor"
func NewGradeSection(name string, totalPoints float64, percentWorth float64) *GradeSection {
	// allocate, zero, and initialize memory, then return pointer to memory
	return &GradeSection{name, 0, totalPoints, percentWorth / 100.0}
}

// GradeSection "Constructor" but using only percent values
func NewGradeSectionPercent(name string, earnedPercent float64, percentWorth float64) *GradeSection {
	return &GradeSection{name, earnedPercent, 100.0, percentWorth / 100.0}
}

func (gs GradeSection) CalcContribution() float64 {
	return gs.CalcGrade() * gs.percentWorth
}

// Calculates grade for provided GradeSection (0.0 - 1.0)
func (gs GradeSection) CalcGrade() float64 {
	return gs.earnedPoints / gs.totalPoints
}

func (gs GradeSection) CalcGradePercent() float64 {
	return gs.CalcGrade() * 100.0
}
