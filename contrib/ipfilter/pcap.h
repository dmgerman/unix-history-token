begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: pcap.h,v 2.2.2.1 2001/06/26 10:43:20 darrenr Exp $  */
end_comment

begin_comment
comment|/*  * This header file is constructed to match the version described by  * PCAP_VERSION_MAJ.  *  * The structure largely derives from libpcap which wouldn't include  * nicely without bpf.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pcap_filehdr
block|{
name|u_int
name|pc_id
decl_stmt|;
name|u_short
name|pc_v_maj
decl_stmt|;
name|u_short
name|pc_v_min
decl_stmt|;
name|u_int
name|pc_zone
decl_stmt|;
name|u_int
name|pc_sigfigs
decl_stmt|;
name|u_int
name|pc_slen
decl_stmt|;
name|u_int
name|pc_type
decl_stmt|;
block|}
name|pcaphdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCPDUMP_MAGIC
value|0xa1b2c3d4
end_define

begin_define
define|#
directive|define
name|PCAP_VERSION_MAJ
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|pcap_pkthdr
block|{
name|struct
name|timeval
name|ph_ts
decl_stmt|;
name|u_int
name|ph_clen
decl_stmt|;
name|u_int
name|ph_len
decl_stmt|;
block|}
name|pcappkt_t
typedef|;
end_typedef

end_unit

