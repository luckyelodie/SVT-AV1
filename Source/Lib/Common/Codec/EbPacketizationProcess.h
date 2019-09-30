/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbPacketization_h
#define EbPacketization_h

#include "EbDefinitions.h"
#include "EbSystemResourceManager.h"
#ifdef __cplusplus
extern "C" {
#endif

    /**************************************
     * Type Declarations
     **************************************/
    typedef struct EbPPSConfig
    {
        uint8_t pps_id;
        uint8_t constrained_flag;
    } EbPPSConfig;

    /**************************************
     * Context
     **************************************/
    typedef struct PacketizationContext
    {
        EbFifo      *entropy_coding_input_fifo_ptr;
        EbFifo      *rate_control_tasks_output_fifo_ptr;
        EbPPSConfig *pps_config;

        uint64_t   dpb_disp_order[8], dpb_dec_order[8];
        uint64_t   tot_shown_frames;
        uint64_t   disp_order_continuity_count;

    } PacketizationContext;

    /**************************************
     * Extern Function Declarations
     **************************************/
    extern EbErrorType packetization_context_ctor(
        PacketizationContext **context_dbl_ptr,
        EbFifo                *entropy_coding_input_fifo_ptr,
        EbFifo                *rate_control_tasks_output_fifo_ptr);



    extern void* packetization_kernel(void *input_ptr);
#ifdef __cplusplus
}
#endif
#endif // EbPacketization_h
