begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)bpf_compat.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* from: $Header: bpf_compat.h,v 1.1 92/05/22 15:33:20 mccanne Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Some hacks for compatibility across SunOS and 4.4BSD.  We emulate malloc  * and free with mbuf clusters.  We store a pointer to the mbuf in the first  * word of the mbuf and return 8 bytes passed the start of data (for double  * word alignment).  We cannot just use offsets because clusters are not at  * a fixed offset from the associated mbuf.  Sorry for this kludge.  */
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|size
parameter_list|,
name|type
parameter_list|,
name|canwait
parameter_list|)
value|bpf_alloc(size, canwait)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|cp
parameter_list|,
name|type
parameter_list|)
value|m_free(*(struct mbuf **)(cp - 8))
end_define

begin_define
define|#
directive|define
name|M_WAITOK
value|M_WAIT
end_define

begin_comment
comment|/* This mapping works for our purposes. */
end_comment

begin_define
define|#
directive|define
name|ERESTART
value|EINTR
end_define

end_unit

