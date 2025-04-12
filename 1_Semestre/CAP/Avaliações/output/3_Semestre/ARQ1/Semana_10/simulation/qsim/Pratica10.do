onerror {quit -f}
vlib work
vlog -work work Pratica10.vo
vlog -work work Pratica10.vt
vsim -novopt -c -t 1ps -L cycloneiv_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.aludec_vlg_vec_tst
vcd file -direction Pratica10.msim.vcd
vcd add -internal aludec_vlg_vec_tst/*
vcd add -internal aludec_vlg_vec_tst/i1/*
add wave /*
run -all
