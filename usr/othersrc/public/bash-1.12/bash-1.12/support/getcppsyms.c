begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getcppsyms.c - Find unique compiler symbols. */
end_comment

begin_comment
comment|/* Some cpp's do not define any symbols, but instead let /bin/cc do it    for them.  For such machines, running this file may prove useful.  It    outputs the list of symbols which /bin/cc or /lib/cpp define and which    we had the foresight to guess at. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|CMU
argument_list|)
name|printf
argument_list|(
literal|" -DCMU"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* CMU */
if|#
directive|if
name|defined
argument_list|(
name|DGUX
argument_list|)
name|printf
argument_list|(
literal|" -DDGUX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DGUX */
if|#
directive|if
name|defined
argument_list|(
name|GOULD_PN
argument_list|)
name|printf
argument_list|(
literal|" -DGOULD_PN"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* GOULD_PN */
if|#
directive|if
name|defined
argument_list|(
name|MIPSEB
argument_list|)
name|printf
argument_list|(
literal|" -DMIPSEB"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MIPSEB */
if|#
directive|if
name|defined
argument_list|(
name|MIPSEL
argument_list|)
name|printf
argument_list|(
literal|" -DMIPSEL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MIPSEL */
if|#
directive|if
name|defined
argument_list|(
name|MULTIMAX
argument_list|)
name|printf
argument_list|(
literal|" -DMULTIMAX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MULTIMAX */
if|#
directive|if
name|defined
argument_list|(
name|M_UNIX
argument_list|)
name|printf
argument_list|(
literal|" -DM_UNIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* M_UNIX */
if|#
directive|if
name|defined
argument_list|(
name|M_XENIX
argument_list|)
name|printf
argument_list|(
literal|" -DM_XENIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* M_XENIX */
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
name|printf
argument_list|(
literal|" -DNeXT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NeXT */
if|#
directive|if
name|defined
argument_list|(
name|RES
argument_list|)
name|printf
argument_list|(
literal|" -DRES"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RES */
if|#
directive|if
name|defined
argument_list|(
name|RISC6000
argument_list|)
name|printf
argument_list|(
literal|" -DRISC6000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RISC6000 */
if|#
directive|if
name|defined
argument_list|(
name|RT
argument_list|)
name|printf
argument_list|(
literal|" -DRT"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* RT */
if|#
directive|if
name|defined
argument_list|(
name|SYSTYPE_BSD
argument_list|)
name|printf
argument_list|(
literal|" -DSYSTYPE_BSD"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SYSTYPE_BSD */
if|#
directive|if
name|defined
argument_list|(
name|SYSTYPE_SYSV
argument_list|)
name|printf
argument_list|(
literal|" -DSYSTYPE_SYSV"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SYSTYPE_SYSV */
if|#
directive|if
name|defined
argument_list|(
name|Sun386i
argument_list|)
name|printf
argument_list|(
literal|" -DSun386i"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Sun386i */
if|#
directive|if
name|defined
argument_list|(
name|Tek4132
argument_list|)
name|printf
argument_list|(
literal|" -DTek4132"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Tek4132 */
if|#
directive|if
name|defined
argument_list|(
name|Tek4300
argument_list|)
name|printf
argument_list|(
literal|" -DTek4300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Tek4300 */
if|#
directive|if
name|defined
argument_list|(
name|UMAXV
argument_list|)
name|printf
argument_list|(
literal|" -DUMAXV"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* UMAXV */
if|#
directive|if
name|defined
argument_list|(
name|USGr4
argument_list|)
name|printf
argument_list|(
literal|" -DUSGr4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* USGr4 */
if|#
directive|if
name|defined
argument_list|(
name|Xenix286
argument_list|)
name|printf
argument_list|(
literal|" -DXenix286"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Xenix286 */
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
name|printf
argument_list|(
literal|" -D_AIX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _AIX */
if|#
directive|if
name|defined
argument_list|(
name|_AIX370
argument_list|)
name|printf
argument_list|(
literal|" -D_AIX370"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _AIX370 */
if|#
directive|if
name|defined
argument_list|(
name|_CX_UX
argument_list|)
name|printf
argument_list|(
literal|" -D_CX_UX"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _CX_UX */
if|#
directive|if
name|defined
argument_list|(
name|_IBMR2
argument_list|)
name|printf
argument_list|(
literal|" -D_IBMR2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _IBMR2 */
if|#
directive|if
name|defined
argument_list|(
name|_M88K
argument_list|)
name|printf
argument_list|(
literal|" -D_M88K"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* _M88K */
if|#
directive|if
name|defined
argument_list|(
name|__DGUX__
argument_list|)
name|printf
argument_list|(
literal|" -D__DGUX__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __DGUX__ */
if|#
directive|if
name|defined
argument_list|(
name|__UMAXV__
argument_list|)
name|printf
argument_list|(
literal|" -D__UMAXV__"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __UMAXV__ */
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s200
argument_list|)
name|printf
argument_list|(
literal|" -D__hp9000s200"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hp9000s200 */
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s300
argument_list|)
name|printf
argument_list|(
literal|" -D__hp9000s300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hp9000s300 */
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s500
argument_list|)
name|printf
argument_list|(
literal|" -D__hp9000s500"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hp9000s500 */
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s700
argument_list|)
name|printf
argument_list|(
literal|" -D__hp9000s700"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hp9000s700 */
if|#
directive|if
name|defined
argument_list|(
name|__hp9000s800
argument_list|)
name|printf
argument_list|(
literal|" -D__hp9000s800"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hp9000s800 */
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
name|printf
argument_list|(
literal|" -D__hpux"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __hpux */
if|#
directive|if
name|defined
argument_list|(
name|__m88k
argument_list|)
name|printf
argument_list|(
literal|" -D__m88k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __m88k */
if|#
directive|if
name|defined
argument_list|(
name|__uxpm__
argument_list|)
name|printf
argument_list|(
literal|" -DUSGr4 -Du370"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __uxpm__ */
if|#
directive|if
name|defined
argument_list|(
name|aix
argument_list|)
name|printf
argument_list|(
literal|" -Daix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* aix */
if|#
directive|if
name|defined
argument_list|(
name|aixpc
argument_list|)
name|printf
argument_list|(
literal|" -Daixpc"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* aixpc */
if|#
directive|if
name|defined
argument_list|(
name|apollo
argument_list|)
name|printf
argument_list|(
literal|" -Dapollo"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* apollo */
if|#
directive|if
name|defined
argument_list|(
name|ardent
argument_list|)
name|printf
argument_list|(
literal|" -Dardent"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ardent */
if|#
directive|if
name|defined
argument_list|(
name|att386
argument_list|)
name|printf
argument_list|(
literal|" -Datt386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* att386 */
if|#
directive|if
name|defined
argument_list|(
name|att3b
argument_list|)
name|printf
argument_list|(
literal|" -Datt3b"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* att3b */
if|#
directive|if
name|defined
argument_list|(
name|bsd4_2
argument_list|)
name|printf
argument_list|(
literal|" -Dbsd4_2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* bsd4_2 */
if|#
directive|if
name|defined
argument_list|(
name|bsd4_3
argument_list|)
name|printf
argument_list|(
literal|" -Dbsd4_3"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* bsd4_3 */
if|#
directive|if
name|defined
argument_list|(
name|cadmus
argument_list|)
name|printf
argument_list|(
literal|" -Dcadmus"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* cadmus */
if|#
directive|if
name|defined
argument_list|(
name|clipper
argument_list|)
name|printf
argument_list|(
literal|" -Dclipper"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* clipper */
if|#
directive|if
name|defined
argument_list|(
name|concurrent
argument_list|)
name|printf
argument_list|(
literal|" -Dconcurrent"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* concurrent */
if|#
directive|if
name|defined
argument_list|(
name|convex
argument_list|)
operator|||
name|defined
argument_list|(
name|__convex__
argument_list|)
operator|||
name|defined
argument_list|(
name|__convexc__
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|printf
argument_list|(
literal|" -pcc"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !__GNUC__ */
name|printf
argument_list|(
literal|" -Dconvex"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* convex */
if|#
directive|if
name|defined
argument_list|(
name|dmert
argument_list|)
name|printf
argument_list|(
literal|" -Ddmert"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* dmert */
if|#
directive|if
name|defined
argument_list|(
name|gcos
argument_list|)
name|printf
argument_list|(
literal|" -Dgcos"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* gcos */
if|#
directive|if
name|defined
argument_list|(
name|gcx
argument_list|)
name|printf
argument_list|(
literal|" -Dgcx"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* gcx */
if|#
directive|if
name|defined
argument_list|(
name|gould
argument_list|)
name|printf
argument_list|(
literal|" -Dgould"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* gould */
if|#
directive|if
name|defined
argument_list|(
name|hbullx20
argument_list|)
name|printf
argument_list|(
literal|" -Dhbullx20"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hbullx20 */
if|#
directive|if
name|defined
argument_list|(
name|hcx
argument_list|)
name|printf
argument_list|(
literal|" -Dhcx"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hcx */
if|#
directive|if
name|defined
argument_list|(
name|host_mips
argument_list|)
name|printf
argument_list|(
literal|" -Dhost_mips"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* host_mips */
if|#
directive|if
name|defined
argument_list|(
name|hp9000
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000 */
if|#
directive|if
name|defined
argument_list|(
name|hp9000s200
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000s200"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000s200 */
if|#
directive|if
name|defined
argument_list|(
name|hp9000s300
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000s300"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000s300 */
if|#
directive|if
name|defined
argument_list|(
name|hp9000s500
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000s500"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000s500 */
if|#
directive|if
name|defined
argument_list|(
name|hp9000s700
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000s700"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000s700 */
if|#
directive|if
name|defined
argument_list|(
name|hp9000s800
argument_list|)
name|printf
argument_list|(
literal|" -Dhp9000s800"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hp9000s800 */
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
name|printf
argument_list|(
literal|" -Dhpux"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* hpux */
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
name|printf
argument_list|(
literal|" -Di386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* i386 */
if|#
directive|if
name|defined
argument_list|(
name|ibm
argument_list|)
name|printf
argument_list|(
literal|" -Dibm"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ibm */
if|#
directive|if
name|defined
argument_list|(
name|ibm032
argument_list|)
name|printf
argument_list|(
literal|" -Dibm032"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ibm032 */
if|#
directive|if
name|defined
argument_list|(
name|ibmrt
argument_list|)
name|printf
argument_list|(
literal|" -Dibmrt"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ibmrt */
if|#
directive|if
name|defined
argument_list|(
name|interdata
argument_list|)
name|printf
argument_list|(
literal|" -Dinterdata"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* interdata */
if|#
directive|if
name|defined
argument_list|(
name|is68k
argument_list|)
name|printf
argument_list|(
literal|" -Dis68k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* is68k */
if|#
directive|if
name|defined
argument_list|(
name|luna88k
argument_list|)
name|printf
argument_list|(
literal|" -Dluna88k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* luna88k */
if|#
directive|if
name|defined
argument_list|(
name|m68k
argument_list|)
name|printf
argument_list|(
literal|" -Dm68k"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* m68k */
if|#
directive|if
name|defined
argument_list|(
name|mc68010
argument_list|)
name|printf
argument_list|(
literal|" -Dmc68010"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mc68010 */
if|#
directive|if
name|defined
argument_list|(
name|mc68020
argument_list|)
name|printf
argument_list|(
literal|" -Dmc68020"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mc68020 */
if|#
directive|if
name|defined
argument_list|(
name|mc68030
argument_list|)
name|printf
argument_list|(
literal|" -Dmc68030"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mc68030 */
if|#
directive|if
name|defined
argument_list|(
name|mc68040
argument_list|)
name|printf
argument_list|(
literal|" -Dmc68040"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mc68040 */
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
name|printf
argument_list|(
literal|" -Dmips"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* mips */
if|#
directive|if
name|defined
argument_list|(
name|n16
argument_list|)
name|printf
argument_list|(
literal|" -Dn16"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* n16 */
if|#
directive|if
name|defined
argument_list|(
name|ns32000
argument_list|)
name|printf
argument_list|(
literal|" -Dns32000"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ns32000 */
if|#
directive|if
name|defined
argument_list|(
name|os
argument_list|)
name|printf
argument_list|(
literal|" -Dos"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* os */
if|#
directive|if
name|defined
argument_list|(
name|pdp11
argument_list|)
name|printf
argument_list|(
literal|" -Dpdp11"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* pdp11 */
if|#
directive|if
name|defined
argument_list|(
name|pyr
argument_list|)
name|printf
argument_list|(
literal|" -Dpyr"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* pyr */
if|#
directive|if
name|defined
argument_list|(
name|sequent
argument_list|)
name|printf
argument_list|(
literal|" -Dsequent"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sequent */
if|#
directive|if
name|defined
argument_list|(
name|sgi
argument_list|)
name|printf
argument_list|(
literal|" -Dsgi"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sgi */
if|#
directive|if
name|defined
argument_list|(
name|sony
argument_list|)
name|printf
argument_list|(
literal|" -Dsony"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sony */
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
name|printf
argument_list|(
literal|" -Dsparc"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sparc */
if|#
directive|if
name|defined
argument_list|(
name|stardent
argument_list|)
name|printf
argument_list|(
literal|" -Dstardent"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* stardent */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
name|printf
argument_list|(
literal|" -Dsun"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sun */
if|#
directive|if
name|defined
argument_list|(
name|sun2
argument_list|)
name|printf
argument_list|(
literal|" -Dsun2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sun2 */
if|#
directive|if
name|defined
argument_list|(
name|sun3
argument_list|)
name|printf
argument_list|(
literal|" -Dsun3"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sun3 */
if|#
directive|if
name|defined
argument_list|(
name|sun4
argument_list|)
name|printf
argument_list|(
literal|" -Dsun4"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* sun4 */
if|#
directive|if
name|defined
argument_list|(
name|tower32
argument_list|)
name|printf
argument_list|(
literal|" -Dtower32"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* tower32 */
if|#
directive|if
name|defined
argument_list|(
name|tss
argument_list|)
name|printf
argument_list|(
literal|" -Dtss"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* tss */
if|#
directive|if
name|defined
argument_list|(
name|u370
argument_list|)
name|printf
argument_list|(
literal|" -Du370"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* u370 */
if|#
directive|if
name|defined
argument_list|(
name|u3b
argument_list|)
name|printf
argument_list|(
literal|" -Du3b"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* u3b */
if|#
directive|if
name|defined
argument_list|(
name|u3b2
argument_list|)
name|printf
argument_list|(
literal|" -Du3b2"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* u3b2 */
if|#
directive|if
name|defined
argument_list|(
name|u3b20d
argument_list|)
name|printf
argument_list|(
literal|" -Du3b20d"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* u3b20d */
if|#
directive|if
name|defined
argument_list|(
name|u3b5
argument_list|)
name|printf
argument_list|(
literal|" -Du3b5"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* u3b5 */
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
name|printf
argument_list|(
literal|" -Dultrix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ultrix */
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
name|printf
argument_list|(
literal|" -Dunix"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* unix */
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
name|printf
argument_list|(
literal|" -Dvax"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* vax */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

