begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  @(#)sigtab.h	34.2  10/24/80  */
end_comment

begin_comment
comment|/*  *  lispvals in use by the program should be in this table.  *  Otherwise they may get garbage-collected.  */
end_comment

begin_define
define|#
directive|define
name|SIGNIF
value|116
end_define

begin_decl_stmt
specifier|extern
name|lispval
name|lispsys
index|[
name|SIGNIF
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tatom
value|(lispsys[1])
end_define

begin_define
define|#
directive|define
name|lambda
value|(lispsys[2])
end_define

begin_define
define|#
directive|define
name|nlambda
value|(lispsys[3])
end_define

begin_define
define|#
directive|define
name|perda
value|(lispsys[4])
end_define

begin_define
define|#
directive|define
name|lpara
value|(lispsys[5])
end_define

begin_define
define|#
directive|define
name|rpara
value|(lispsys[6])
end_define

begin_define
define|#
directive|define
name|lbkta
value|(lispsys[7])
end_define

begin_define
define|#
directive|define
name|rbkta
value|(lispsys[8])
end_define

begin_define
define|#
directive|define
name|Eofa
value|(lispsys[9])
end_define

begin_define
define|#
directive|define
name|snqta
value|(lispsys[10])
end_define

begin_define
define|#
directive|define
name|exclpa
value|(lispsys[11])
end_define

begin_define
define|#
directive|define
name|quota
value|(lispsys[12])
end_define

begin_define
define|#
directive|define
name|xatom
value|(lispsys[13])
end_define

begin_define
define|#
directive|define
name|cara
value|(lispsys[14])
end_define

begin_define
define|#
directive|define
name|cdra
value|(lispsys[15])
end_define

begin_define
define|#
directive|define
name|gcafter
value|(lispsys[16])
end_define

begin_define
define|#
directive|define
name|noptop
value|(lispsys[17])
end_define

begin_define
define|#
directive|define
name|gcthresh
value|(lispsys[18])
end_define

begin_define
define|#
directive|define
name|int_name
value|(lispsys[19])
end_define

begin_define
define|#
directive|define
name|str_name
value|(lispsys[20])
end_define

begin_define
define|#
directive|define
name|atom_name
value|(lispsys[21])
end_define

begin_define
define|#
directive|define
name|doub_name
value|(lispsys[22])
end_define

begin_define
define|#
directive|define
name|dtpr_name
value|(lispsys[23])
end_define

begin_define
define|#
directive|define
name|int_items
value|(lispsys[24])
end_define

begin_define
define|#
directive|define
name|int_pages
value|(lispsys[25])
end_define

begin_define
define|#
directive|define
name|str_items
value|(lispsys[26])
end_define

begin_define
define|#
directive|define
name|str_pages
value|(lispsys[27])
end_define

begin_define
define|#
directive|define
name|dtpr_items
value|(lispsys[28])
end_define

begin_define
define|#
directive|define
name|dtpr_pages
value|(lispsys[29])
end_define

begin_define
define|#
directive|define
name|doub_items
value|(lispsys[30])
end_define

begin_define
define|#
directive|define
name|doub_pages
value|(lispsys[31])
end_define

begin_define
define|#
directive|define
name|atom_items
value|(lispsys[32])
end_define

begin_define
define|#
directive|define
name|atom_pages
value|(lispsys[33])
end_define

begin_define
define|#
directive|define
name|gccall1
value|(lispsys[34])
end_define

begin_define
define|#
directive|define
name|gccall2
value|(lispsys[35])
end_define

begin_define
define|#
directive|define
name|sysa
value|(lispsys[36])
end_define

begin_define
define|#
directive|define
name|plima
value|(lispsys[37])
end_define

begin_define
define|#
directive|define
name|macro
value|(lispsys[38])
end_define

begin_define
define|#
directive|define
name|startup
value|(lispsys[39])
end_define

begin_define
define|#
directive|define
name|rcomms
value|(lispsys[40])
end_define

begin_define
define|#
directive|define
name|commta
value|(lispsys[41])
end_define

begin_define
define|#
directive|define
name|plimit
value|(lispsys[44])
end_define

begin_define
define|#
directive|define
name|array_items
value|(lispsys[45])
end_define

begin_define
define|#
directive|define
name|array_pages
value|(lispsys[46])
end_define

begin_define
define|#
directive|define
name|array_name
value|(lispsys[47])
end_define

begin_define
define|#
directive|define
name|sdot_items
value|(lispsys[48])
end_define

begin_define
define|#
directive|define
name|sdot_pages
value|(lispsys[49])
end_define

begin_define
define|#
directive|define
name|sdot_name
value|(lispsys[50])
end_define

begin_define
define|#
directive|define
name|val_items
value|(lispsys[51])
end_define

begin_define
define|#
directive|define
name|val_pages
value|(lispsys[52])
end_define

begin_define
define|#
directive|define
name|val_name
value|(lispsys[53])
end_define

begin_define
define|#
directive|define
name|splice
value|(lispsys[54])
end_define

begin_define
define|#
directive|define
name|rdrsdot
value|(lispsys[55])
end_define

begin_define
define|#
directive|define
name|funct_items
value|(lispsys[56])
end_define

begin_define
define|#
directive|define
name|funct_pages
value|(lispsys[57])
end_define

begin_define
define|#
directive|define
name|funct_name
value|(lispsys[58])
end_define

begin_define
define|#
directive|define
name|nstack
value|(lispsys[59])
end_define

begin_define
define|#
directive|define
name|rdrint
value|(lispsys[63])
end_define

begin_define
define|#
directive|define
name|nilplist
value|(lispsys[64])
end_define

begin_define
define|#
directive|define
name|badst
value|(lispsys[65])
end_define

begin_define
define|#
directive|define
name|gccheck
value|(lispsys[66])
end_define

begin_define
define|#
directive|define
name|gcport
value|(lispsys[67])
end_define

begin_define
define|#
directive|define
name|gcdis
value|(lispsys[68])
end_define

begin_define
define|#
directive|define
name|gcload
value|(lispsys[69])
end_define

begin_define
define|#
directive|define
name|loading
value|(lispsys[70])
end_define

begin_define
define|#
directive|define
name|noautot
value|(lispsys[71])
end_define

begin_define
define|#
directive|define
name|lcode
value|(lispsys[72])
end_define

begin_define
define|#
directive|define
name|ccode
value|(lispsys[73])
end_define

begin_define
define|#
directive|define
name|odform
value|(lispsys[74])
end_define

begin_define
define|#
directive|define
name|bcdst
value|(lispsys[75])
end_define

begin_define
define|#
directive|define
name|listst
value|(lispsys[76])
end_define

begin_define
define|#
directive|define
name|macrost
value|(lispsys[77])
end_define

begin_define
define|#
directive|define
name|protst
value|(lispsys[78])
end_define

begin_define
define|#
directive|define
name|argst
value|(lispsys[79])
end_define

begin_define
define|#
directive|define
name|arrayst
value|(lispsys[80])
end_define

begin_define
define|#
directive|define
name|proga
value|(lispsys[81])
end_define

begin_define
define|#
directive|define
name|progma
value|(lispsys[82])
end_define

begin_define
define|#
directive|define
name|bstack
value|(lispsys[83])
end_define

begin_define
define|#
directive|define
name|lexpr_atom
value|(lispsys[84])
end_define

begin_define
define|#
directive|define
name|lexpr
value|(lispsys[85])
end_define

begin_define
define|#
directive|define
name|ibase
value|(lispsys[86])
end_define

begin_define
define|#
directive|define
name|Vpiport
value|(lispsys[87])
end_define

begin_define
define|#
directive|define
name|Vpoport
value|(lispsys[88])
end_define

begin_define
define|#
directive|define
name|Veval
value|(lispsys[89])
end_define

begin_define
define|#
directive|define
name|Vererr
value|(lispsys[90])
end_define

begin_define
define|#
directive|define
name|Vertpl
value|(lispsys[91])
end_define

begin_define
define|#
directive|define
name|Verall
value|(lispsys[92])
end_define

begin_define
define|#
directive|define
name|Vermisc
value|(lispsys[93])
end_define

begin_define
define|#
directive|define
name|Vlerall
value|(lispsys[94])
end_define

begin_define
define|#
directive|define
name|stlist
value|(lispsys[95])
end_define

begin_define
define|#
directive|define
name|Vreadtable
value|(lispsys[96])
end_define

begin_define
define|#
directive|define
name|strtab
value|(lispsys[97])
end_define

begin_define
define|#
directive|define
name|Verbrk
value|(lispsys[98])
end_define

begin_define
define|#
directive|define
name|Vnogbar
value|(lispsys[99])
end_define

begin_define
define|#
directive|define
name|rdrsdot2
value|(lispsys[100])
end_define

begin_define
define|#
directive|define
name|Veruwpt
value|(lispsys[101])
end_define

begin_define
define|#
directive|define
name|hunkfree
value|(lispsys[102])
end_define

begin_define
define|#
directive|define
name|port_name
value|(lispsys[103])
end_define

begin_define
define|#
directive|define
name|reseta
value|(lispsys[104])
end_define

begin_define
define|#
directive|define
name|rsetatom
value|(lispsys[105])
end_define

begin_define
define|#
directive|define
name|bptr_atom
value|(lispsys[106])
end_define

begin_define
define|#
directive|define
name|evalhatom
value|(lispsys[107])
end_define

begin_define
define|#
directive|define
name|evalhcall
value|(lispsys[108])
end_define

begin_define
define|#
directive|define
name|Vptport
value|(lispsys[109])
end_define

begin_define
define|#
directive|define
name|Vcntlw
value|(lispsys[110])
end_define

begin_define
define|#
directive|define
name|Verrset
value|(lispsys[111])
end_define

begin_define
define|#
directive|define
name|Verundef
value|(lispsys[112])
end_define

begin_define
define|#
directive|define
name|Vsubrou
value|(lispsys[113])
end_define

begin_define
define|#
directive|define
name|Vprinlevel
value|(lispsys[114])
end_define

begin_define
define|#
directive|define
name|Vprinlength
value|(lispsys[115])
end_define

begin_comment
comment|/* various status switches */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONTORT
end_ifndef

begin_decl_stmt
specifier|extern
name|lispval
name|stattab
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Schainp
value|(stattab[0])
end_define

begin_define
define|#
directive|define
name|Sautor
value|(stattab[1])
end_define

begin_define
define|#
directive|define
name|Strans
value|(stattab[2])
end_define

begin_define
define|#
directive|define
name|evalhsw
value|(stattab[3])
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

