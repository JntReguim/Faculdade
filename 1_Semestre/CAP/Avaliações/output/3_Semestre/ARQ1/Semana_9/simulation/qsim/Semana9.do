onerror {quit -f}
vlib work
vlog -work work Semana9.vo
vlog -work work Semana9.vt
vsim -novopt -c -t 1ps -L cycloneiv_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.dmem_vlg_vec_tst
vcd file -direction Semana9.msim.vcd
vcd add -internal dmem_vlg_vec_tst/*
vcd add -internal dmem_vlg_vec_tst/i1/*
add wave /*
run -all
