begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: bpfdesc.h,v 1.7 90/12/04 01:05:01 mccanne Exp $ (LBL)  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enetdefs.h) distributed in 4.3BSD Unix.  */
end_comment

begin_comment
comment|/*  * Descriptor associated with each open bpf file.  */
end_comment

begin_struct
struct|struct
name|bpf_d
block|{
name|struct
name|bpf_d
modifier|*
name|bd_next
decl_stmt|;
comment|/* Linked list of descriptors */
comment|/* 	 * Buffer slots: two mbuf clusters buffer the incoming packets. 	 *   The model has three slots.  Sbuf is always occupied. 	 *   sbuf (store) - Receive interrupt puts packets here. 	 *   hbuf (hold) - When sbuf is full, put cluster here and 	 *                 wakeup read (replace sbuf with fbuf). 	 *   fbuf (free) - When read is done, put cluster here. 	 * On receiving, if sbuf is full and fbuf is 0, packet is dropped. 	 */
name|caddr_t
name|bd_sbuf
decl_stmt|;
comment|/* store slot */
name|caddr_t
name|bd_hbuf
decl_stmt|;
comment|/* hold slot */
name|caddr_t
name|bd_fbuf
decl_stmt|;
comment|/* free slot */
name|int
name|bd_slen
decl_stmt|;
comment|/* current length of store buffer */
name|int
name|bd_hlen
decl_stmt|;
comment|/* current length of hold buffer */
name|int
name|bd_bufsize
decl_stmt|;
comment|/* absolute length of buffers */
name|struct
name|bpf_if
modifier|*
name|bd_bif
decl_stmt|;
comment|/* interface descriptor */
name|u_long
name|bd_rtout
decl_stmt|;
comment|/* Read timeout in 'ticks' */
name|struct
name|bpf_insn
modifier|*
name|bd_filter
decl_stmt|;
comment|/* filter code */
name|u_long
name|bd_rcount
decl_stmt|;
comment|/* number of packets received */
name|u_long
name|bd_dcount
decl_stmt|;
comment|/* number of packets dropped */
name|struct
name|proc
modifier|*
name|bd_selproc
decl_stmt|;
comment|/* process that last selected us */
name|u_char
name|bd_promisc
decl_stmt|;
comment|/* true if listening promiscuously */
name|u_char
name|bd_state
decl_stmt|;
comment|/* idle, waiting, or timed out */
name|u_char
name|bd_selcoll
decl_stmt|;
comment|/* true if selects collide */
name|u_char
name|bd_immediate
decl_stmt|;
comment|/* true to return on packet arrival */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Descriptor associated with each attached hardware interface.  */
end_comment

begin_struct
struct|struct
name|bpf_if
block|{
comment|/* List of descriptors listening on this interface. */
name|struct
name|bpf_d
modifier|*
name|bif_dlist
decl_stmt|;
comment|/* Pointer to the device driver's softc bpf field. */
name|struct
name|bpf_if
modifier|*
modifier|*
name|bif_driverp
decl_stmt|;
comment|/* Device parameters, see bpf.h. */
name|struct
name|bpf_devp
name|bif_devp
decl_stmt|;
comment|/* Length of bpf header (bpf_hdr + padding). */
name|u_int
name|bif_hdrlen
decl_stmt|;
comment|/* 'ifnet' of associated interface. */
name|struct
name|ifnet
modifier|*
name|bif_ifp
decl_stmt|;
block|}
struct|;
end_struct

end_unit

