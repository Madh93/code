package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func toRot13(b byte) byte {

	if b >= 'A' && b <= 'Z' {
		return 'A' + ((b - 'A' + 13) % 26)
	} else if b >= 'a' && b <= 'z' {
		return 'a' + ((b - 'a' + 13) % 26)
	}

	return b
}

func (rot *rot13Reader) Read(b []byte) (n int, err error) {
	n, err = rot.r.Read(b)

	for i := 0; i < len(b); i++ {
		b[i] = toRot13(b[i])
	}

	return
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
