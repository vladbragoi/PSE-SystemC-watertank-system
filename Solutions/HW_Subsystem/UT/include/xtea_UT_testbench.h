//
// Created by vlad on 18/12/18.
//

#pragma once

#include <systemc.h>
#include <tlm.h>
#include "define_UT.h"

class xtea_UT_testbench : public sc_module,
                          public virtual tlm::tlm_bw_transport_if<> {
private:
    void invalidate_direct_mem_ptr(uint64 start_range, uint64 end_range) override;

    tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &trans, tlm::tlm_phase &phase, sc_time &t) override;
    void run();

public:
    SC_HAS_PROCESS(xtea_UT_testbench);

    explicit xtea_UT_testbench(sc_module_name name);

    tlm::tlm_initiator_socket<> initiator_socket;
};
