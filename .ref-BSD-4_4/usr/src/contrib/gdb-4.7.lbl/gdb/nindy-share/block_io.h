begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************/
end_comment

begin_expr_stmt
name|Copyright
literal|1990
operator|,
literal|1992
name|Free
name|Software
name|Foundation
operator|,
name|Inc
operator|.
name|This
name|code
name|was
name|donated
name|by
name|Intel
name|Corp
operator|.
name|Intel
name|hereby
name|grants
name|you
name|permission
name|to
name|copy
operator|,
name|modify
operator|,
name|and
name|distribute
name|this
name|software
name|and
name|its
name|documentation
operator|.
name|Intel
name|grants
name|this
name|permission
name|provided
name|that
name|the
name|above
name|copyright
name|notice
name|appears
name|in
name|all
name|copies
name|and
name|that
name|both
name|the
name|copyright
name|notice
name|and
name|this
name|permission
name|notice
name|appear
name|in
name|supporting
name|documentation
operator|.
name|In
name|addition
operator|,
name|Intel
name|grants
name|this
name|permission
name|provided
name|that
name|you
name|prominently
name|mark
name|as
name|not
name|part
name|of
name|the
name|original
name|any
name|modifications
name|made
name|to
name|this
name|software
name|or
name|documentation
operator|,
name|and
name|that
name|the
name|name
name|of
name|Intel
name|Corporation
name|not
name|be
name|used
name|in
name|advertising
name|or
name|publicity
name|pertaining
name|to
name|distribution
name|of
name|the
name|software
name|or
name|the
name|documentation
name|without
name|specific
operator|,
name|written
name|prior
name|permission
operator|.
name|Intel
name|Corporation
name|does
name|not
name|warrant
operator|,
name|guarantee
name|or
name|make
name|any
name|representations
name|regarding
name|the
name|use
name|of
operator|,
name|or
name|the
name|results
name|of
name|the
name|use
name|of
operator|,
name|the
name|software
name|and
name|documentation
name|in
name|terms
name|of
name|correctness
operator|,
name|accuracy
operator|,
name|reliability
operator|,
name|currentness
operator|,
name|or
name|otherwise
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|and
name|you
name|rely
name|on
name|the
name|software
decl_stmt|,
name|documentation
name|and
name|results
name|solely
name|at
name|your
name|own
name|risk
operator|.
modifier|*
decl|/
end_decl_stmt

begin_comment
comment|/******************************************************************/
end_comment

begin_comment
comment|/*****************************************************************************  * Structures and definitions supporting NINDY requests for services by a  * remote host.  Used by NINDY monitor, library libnin, comm960, gdb960,  * etc.  Also contains some defines for NINDY console I/O requests.  *****************************************************************************/
end_comment

begin_comment
comment|/* the following four are hardware dependent */
end_comment

begin_define
define|#
directive|define
name|BIT_16
value|short
end_define

begin_define
define|#
directive|define
name|BIT_32
value|int
end_define

begin_define
define|#
directive|define
name|UBIT_16
value|unsigned short
end_define

begin_define
define|#
directive|define
name|UBIT_32
value|unsigned int
end_define

begin_comment
comment|/* Service request numbers -- these are the services that can be asked of the  * host.  */
end_comment

begin_define
define|#
directive|define
name|BS_ACCESS
value|0x10
end_define

begin_define
define|#
directive|define
name|BS_CLOSE
value|0x20
end_define

begin_define
define|#
directive|define
name|BS_CREAT
value|0x30
end_define

begin_define
define|#
directive|define
name|BS_SEEK
value|0x40
end_define

begin_define
define|#
directive|define
name|BS_OPEN
value|0x50
end_define

begin_define
define|#
directive|define
name|BS_READ
value|0x60
end_define

begin_define
define|#
directive|define
name|BS_STAT
value|0x70
end_define

begin_define
define|#
directive|define
name|BS_SYSTEMD
value|0x80
end_define

begin_define
define|#
directive|define
name|BS_TIME
value|0x90
end_define

begin_define
define|#
directive|define
name|BS_UNMASK
value|0xa0
end_define

begin_define
define|#
directive|define
name|BS_UNLINK
value|0xb0
end_define

begin_define
define|#
directive|define
name|BS_WRITE
value|0xc0
end_define

begin_comment
comment|/* Maximum number of arguments to any of the above service requests  * (in addition to the request number).  */
end_comment

begin_define
define|#
directive|define
name|MAX_SRQ_ARGS
value|3
end_define

begin_comment
comment|/* Number of bytes of data that can be read or written by a single I/O request  */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|1024
end_define

begin_comment
comment|/* NINDY console I/O requests:  CO sends a single character to stdout,  * CI reads one.  */
end_comment

begin_define
define|#
directive|define
name|CI
value|0
end_define

begin_define
define|#
directive|define
name|CO
value|1
end_define

end_unit

