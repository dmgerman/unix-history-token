begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Parts Copyright (c) 1995 Terrence R. Lambert  * Copyright (c) 1995 Julian R. Elischer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY Julian R. Elischer ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: kern_conf.c,v 1.2 1995/10/02 10:15:40 julian Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_decl_stmt
specifier|extern
name|d_open_t
name|lkmenodev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * (re)place an entry in the bdevsw or cdevsw table  * return the slot used in major(*descrip)  */
end_comment

begin_define
define|#
directive|define
name|ADDENTRY
parameter_list|(
name|TTYPE
parameter_list|,
name|NXXXDEV
parameter_list|)
define|\
value|int TTYPE##_add(dev_t *descrip,						\ 		struct TTYPE *newentry,					\ 		struct TTYPE *oldentry)					\ {									\ 	int i ;								\ 	if ( (int)*descrip == -1) {
comment|/* auto (0 is valid) */
value|\
comment|/*							\ 		 * Search the table looking for a slot...		\ 		 */
value|\ 		for (i = 0; i< NXXXDEV; i++)				\ 			if (TTYPE[i].d_open == lkmenodev)		\ 				break;
comment|/* found it! */
value|\
comment|/* out of allocable slots? */
value|\ 		if (i == NXXXDEV) {					\ 			return ENFILE;					\ 		}							\ 	} else {
comment|/* assign */
value|\ 		i = major(descrip);					\ 		if (i< 0 || i>= NXXXDEV) {				\ 			return EINVAL;					\ 		}							\ 	}								\ 									\
comment|/* maybe save old */
value|\         if (oldentry) {							\ 		bcopy(&TTYPE[i], oldentry, sizeof(struct TTYPE));	\ 	}								\
comment|/* replace with new */
value|\ 	bcopy(newentry,&TTYPE[i], sizeof(struct TTYPE));		\ 									\
comment|/* done! */
value|\ 	*descrip = makedev(i,0);					\ 	return 0;							\ } \  ADDENTRY(bdevsw, nblkdev)
end_define

begin_macro
name|ADDENTRY
argument_list|(
argument|cdevsw
argument_list|,
argument|nchrdev
argument_list|)
end_macro

end_unit

