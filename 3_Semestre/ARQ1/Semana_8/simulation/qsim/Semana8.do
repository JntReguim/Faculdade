onerror {quit -f}
vlib work
vlog -work work Semana8.vo
vlog -work work Semana8.vt
vsim -novopt -c -t 1ps -L cycloneiv_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.extend_vlg_vec_tst
vcd file -direction Semana8.msim.vcd
vcd add -internal extend_vlg_vec_tst/*
vcd add -internal extend_vlg_vec_tst/i1/*
add wave /*
run -all
