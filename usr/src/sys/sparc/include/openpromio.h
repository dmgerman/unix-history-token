begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)openpromio.h	7.1 (Berkeley) %G%  *  * from: $Header: openpromio.h,v 1.2 93/04/20 11:14:46 torek Exp $  */
end_comment

begin_struct
struct|struct
name|opiocdesc
block|{
name|int
name|op_nodeid
decl_stmt|;
comment|/* passed or returned node id */
name|int
name|op_namelen
decl_stmt|;
comment|/* length of op_name */
name|char
modifier|*
name|op_name
decl_stmt|;
comment|/* pointer to field name */
name|int
name|op_buflen
decl_stmt|;
comment|/* length of op_buf (value-result) */
name|char
modifier|*
name|op_buf
decl_stmt|;
comment|/* pointer to field value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OPIOCGET
value|_IOWR('O', 1, struct opiocdesc)
end_define

begin_comment
comment|/* get openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCSET
value|_IOW('O', 2, struct opiocdesc)
end_define

begin_comment
comment|/* set openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCNEXTPROP
value|_IOWR('O', 3, struct opiocdesc)
end_define

begin_comment
comment|/* get next property */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETOPTNODE
value|_IOR('O', 4, int)
end_define

begin_comment
comment|/* get openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETNEXT
value|_IOWR('O', 5, int)
end_define

begin_comment
comment|/* get next node of node */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETCHILD
value|_IOWR('O', 6, int)
end_define

begin_comment
comment|/* get first child of node */
end_comment

end_unit

