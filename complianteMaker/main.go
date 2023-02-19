package main

import (
	_ "embed"
	"os"
	"fmt"
	"text/template"
)

//go:embed template/hpp
var hpp string

//go:embed template/cpp
var cpp string

func create(a string) {
	f, err := os.Create(a + ".hpp")
	if err != nil {
		 return
	}
	tmpl, err := template.New(a).Parse(hpp)
	fmt.Println(tmpl)
	if err != nil { panic(err) }
	err = tmpl.Execute(f, a)
	if err != nil { panic(err) }
}

func creates(a string) {
	f, err := os.Create(a + ".cpp")
	if err != nil {
		 return
	}
	tmpl, err := template.New(a).Parse(cpp)
	fmt.Println(tmpl)
	if err != nil { panic(err) }
	err = tmpl.Execute(f, a)
	if err != nil { panic(err) }
}

func main() {
	if len(os.Args) == 2 {
		create(os.Args[1])
		creates(os.Args[1])
	}
}
