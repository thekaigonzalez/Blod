
import readline

fn main() {
	// mut a := 1
	mut reader := readline.Readline{}
	execv_blod(reader.read_line("type expresion : ") ?)
}

fn execv_blod(code string) {
	mut buffer := ""
	mut fname := ""
	mut state := 10
	mut args := []string{}
	for char in code {
		cur := char.ascii_str()
		// println(state)
		// println(buffer)
		if cur == '(' && state == 10 {
			fname = buffer
			state = 0
			buffer = ""
			// args << fname.trim_space()
		} else if cur == '(' && state != 10 {
			state += 10
			buffer += cur
		} else if cur == '"' && state == 0 {
			state = 9999	
		} else if cur == '"' && state == 9999 {
			state = 0	
		} else if cur == '`' && state == 0 {
			state = 99991	
		} else if cur == '`' && state == 99991 {
			state = 0	
		} else if cur == ')' && state != 0 {
			state -= 10	
			buffer += cur
		} else if cur == ')' && state == 0 {
			if buffer.len > 0 {
				args << buffer.trim_space()
			}
			break	
		} else if cur == ',' && state == 0 {
			args << buffer.trim_space()
			buffer = ""
		} else {
			buffer += cur
		}
	}
	
	if state != 0 {
		println("compiler error: state != 0")
	}
	
	println("semantic analysis complete")
	println(args)
	println(fname)
	println(state)

}