begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%M%	%I%	%E%	*/
end_comment

begin_define
define|#
directive|define
name|ADWRAP
value|kdbADWRAP
end_define

begin_define
define|#
directive|define
name|BADCOM
value|kdbBADCOM
end_define

begin_define
define|#
directive|define
name|BADDAT
value|kdbBADDAT
end_define

begin_define
define|#
directive|define
name|BADEQ
value|kdbBADEQ
end_define

begin_define
define|#
directive|define
name|BADKET
value|kdbBADKET
end_define

begin_define
define|#
directive|define
name|BADLOC
value|kdbBADLOC
end_define

begin_define
define|#
directive|define
name|BADMOD
value|kdbBADMOD
end_define

begin_define
define|#
directive|define
name|BADRAD
value|kdbBADRAD
end_define

begin_define
define|#
directive|define
name|BADSYM
value|kdbBADSYM
end_define

begin_define
define|#
directive|define
name|BADSYN
value|kdbBADSYN
end_define

begin_define
define|#
directive|define
name|BADTXT
value|kdbBADTXT
end_define

begin_define
define|#
directive|define
name|BADVAR
value|kdbBADVAR
end_define

begin_define
define|#
directive|define
name|EXBKPT
value|kdbEXBKPT
end_define

begin_define
define|#
directive|define
name|NOADR
value|kdbNOADR
end_define

begin_define
define|#
directive|define
name|NOBKPT
value|kdbNOBKPT
end_define

begin_define
define|#
directive|define
name|NOCFN
value|kdbNOCFN
end_define

begin_define
define|#
directive|define
name|NOEOR
value|kdbNOEOR
end_define

begin_define
define|#
directive|define
name|NOMATCH
value|kdbNOMATCH
end_define

begin_define
define|#
directive|define
name|SZBKPT
value|kdbSZBKPT
end_define

begin_define
define|#
directive|define
name|adrflg
value|kdbadrflg
end_define

begin_define
define|#
directive|define
name|adrval
value|kdbadrval
end_define

begin_define
define|#
directive|define
name|bchkget
value|kdbbchkget
end_define

begin_define
define|#
directive|define
name|bkpthead
value|kdbbkpthead
end_define

begin_define
define|#
directive|define
name|bpstate
value|kdbbpstate
end_define

begin_define
define|#
directive|define
name|callpc
value|kdbcallpc
end_define

begin_define
define|#
directive|define
name|charpos
value|kdbcharpos
end_define

begin_define
define|#
directive|define
name|chkerr
value|kdbchkerr
end_define

begin_define
define|#
directive|define
name|chkget
value|kdbchkget
end_define

begin_define
define|#
directive|define
name|chkloc
value|kdbchkloc
end_define

begin_define
define|#
directive|define
name|cntflg
value|kdbcntflg
end_define

begin_define
define|#
directive|define
name|cntval
value|kdbcntval
end_define

begin_define
define|#
directive|define
name|command
value|kdbcommand
end_define

begin_define
define|#
directive|define
name|convdig
value|kdbconvdig
end_define

begin_define
define|#
directive|define
name|convert
value|kdbconvert
end_define

begin_define
define|#
directive|define
name|cursym
value|kdbcursym
end_define

begin_define
define|#
directive|define
name|delbp
value|kdbdelbp
end_define

begin_define
define|#
directive|define
name|digitptr
value|kdbdigitptr
end_define

begin_define
define|#
directive|define
name|ditto
value|kdbditto
end_define

begin_define
define|#
directive|define
name|dot
value|kdbdot
end_define

begin_define
define|#
directive|define
name|dotinc
value|kdbdotinc
end_define

begin_define
define|#
directive|define
name|echo
value|kdbecho
end_define

begin_define
define|#
directive|define
name|endline
value|kdbendline
end_define

begin_define
define|#
directive|define
name|eof
value|kdbeof
end_define

begin_define
define|#
directive|define
name|eol
value|kdbeol
end_define

begin_define
define|#
directive|define
name|eqformat
value|kdbeqformat
end_define

begin_define
define|#
directive|define
name|eqsym
value|kdbeqsym
end_define

begin_define
define|#
directive|define
name|errflg
value|kdberrflg
end_define

begin_define
define|#
directive|define
name|error
value|kdberror
end_define

begin_define
define|#
directive|define
name|esymtab
value|kdbesymtab
end_define

begin_define
define|#
directive|define
name|execbkpt
value|kdbexecbkpt
end_define

begin_define
define|#
directive|define
name|execbkptf
value|kdbexecbkptf
end_define

begin_define
define|#
directive|define
name|executing
value|kdbexecuting
end_define

begin_define
define|#
directive|define
name|exform
value|kdbexform
end_define

begin_define
define|#
directive|define
name|expr
value|kdbexpr
end_define

begin_define
define|#
directive|define
name|expv
value|kdbexpv
end_define

begin_define
define|#
directive|define
name|findsym
value|kdbfindsym
end_define

begin_define
define|#
directive|define
name|flushbuf
value|kdbflushbuf
end_define

begin_define
define|#
directive|define
name|get
value|kdbget
end_define

begin_define
define|#
directive|define
name|getformat
value|kdbgetformat
end_define

begin_define
define|#
directive|define
name|getnum
value|kdbgetnum
end_define

begin_define
define|#
directive|define
name|getreg
value|kdbgetreg
end_define

begin_define
define|#
directive|define
name|infile
value|kdbinfile
end_define

begin_define
define|#
directive|define
name|inkdot
value|kdbinkdot
end_define

begin_define
define|#
directive|define
name|isymbol
value|kdbisymbol
end_define

begin_define
define|#
directive|define
name|item
value|kdbitem
end_define

begin_define
define|#
directive|define
name|jmpbuf
value|kdbjmpbuf
end_define

begin_define
define|#
directive|define
name|lastc
value|kdblastc
end_define

begin_define
define|#
directive|define
name|lastcom
value|kdblastcom
end_define

begin_define
define|#
directive|define
name|lastframe
value|kdblastframe
end_define

begin_define
define|#
directive|define
name|line
value|kdbline
end_define

begin_define
define|#
directive|define
name|localsym
value|kdblocalsym
end_define

begin_define
define|#
directive|define
name|localval
value|kdblocalval
end_define

begin_define
define|#
directive|define
name|locmsk
value|kdblocmsk
end_define

begin_define
define|#
directive|define
name|locval
value|kdblocval
end_define

begin_define
define|#
directive|define
name|lookup
value|kdblookup
end_define

begin_define
define|#
directive|define
name|loopcnt
value|kdbloopcnt
end_define

begin_define
define|#
directive|define
name|lp
value|kdblp
end_define

begin_define
define|#
directive|define
name|maxoff
value|kdbmaxoff
end_define

begin_define
define|#
directive|define
name|maxpos
value|kdbmaxpos
end_define

begin_define
define|#
directive|define
name|maxstor
value|kdbmaxstor
end_define

begin_define
define|#
directive|define
name|mkfault
value|kdbmkfault
end_define

begin_define
define|#
directive|define
name|nextchar
value|kdbnextchar
end_define

begin_define
define|#
directive|define
name|nextpcs
value|kdbnextpcs
end_define

begin_define
define|#
directive|define
name|pcb
value|kdbpcb
end_define

begin_define
define|#
directive|define
name|peekc
value|kdbpeekc
end_define

begin_define
define|#
directive|define
name|printbuf
value|kdbprintbuf
end_define

begin_define
define|#
directive|define
name|printc
value|kdbprintc
end_define

begin_define
define|#
directive|define
name|printesc
value|kdbprintesc
end_define

begin_define
define|#
directive|define
name|printf
value|kdbprintf
end_define

begin_define
define|#
directive|define
name|printins
value|kdbprintins
end_define

begin_define
define|#
directive|define
name|printnum
value|kdbprintnum
end_define

begin_define
define|#
directive|define
name|printpc
value|kdbprintpc
end_define

begin_define
define|#
directive|define
name|printptr
value|kdbprintptr
end_define

begin_define
define|#
directive|define
name|printregs
value|kdbprintregs
end_define

begin_define
define|#
directive|define
name|printtrace
value|kdbprinttrace
end_define

begin_define
define|#
directive|define
name|printtrap
value|kdbprinttrap
end_define

begin_define
define|#
directive|define
name|psymoff
value|kdbpsymoff
end_define

begin_define
define|#
directive|define
name|put
value|kdbput
end_define

begin_define
define|#
directive|define
name|quotchar
value|kdbquotchar
end_define

begin_define
define|#
directive|define
name|radix
value|kdbradix
end_define

begin_define
define|#
directive|define
name|rdc
value|kdbrdc
end_define

begin_define
define|#
directive|define
name|readchar
value|kdbreadchar
end_define

begin_define
define|#
directive|define
name|readsym
value|kdbreadsym
end_define

begin_define
define|#
directive|define
name|reglist
value|kdbreglist
end_define

begin_define
define|#
directive|define
name|round
value|kdbround
end_define

begin_define
define|#
directive|define
name|runpcs
value|kdbrunpcs
end_define

begin_define
define|#
directive|define
name|savframe
value|kdbsavframe
end_define

begin_define
define|#
directive|define
name|savlastf
value|kdbsavlastf
end_define

begin_define
define|#
directive|define
name|savpc
value|kdbsavpc
end_define

begin_define
define|#
directive|define
name|scanbkpt
value|kdbscanbkpt
end_define

begin_define
define|#
directive|define
name|scanform
value|kdbscanform
end_define

begin_define
define|#
directive|define
name|setbp
value|kdbsetbp
end_define

begin_define
define|#
directive|define
name|setsym
value|kdbsetsym
end_define

begin_define
define|#
directive|define
name|stformat
value|kdbstformat
end_define

begin_define
define|#
directive|define
name|streq
value|kdbstreq
end_define

begin_define
define|#
directive|define
name|subpcs
value|kdbsubpcs
end_define

begin_define
define|#
directive|define
name|symchar
value|kdbsymchar
end_define

begin_define
define|#
directive|define
name|symtab
value|kdbsymtab
end_define

begin_define
define|#
directive|define
name|term
value|kdbterm
end_define

begin_define
define|#
directive|define
name|userpc
value|kdbuserpc
end_define

begin_define
define|#
directive|define
name|valpr
value|kdbvalpr
end_define

begin_define
define|#
directive|define
name|var
value|kdbvar
end_define

begin_define
define|#
directive|define
name|varchk
value|kdbvarchk
end_define

end_unit

