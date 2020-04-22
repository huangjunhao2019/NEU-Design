# How Linux Capability Works in 2.6.25
## 1.
这篇文章提到
>When a process executes a new program (using exec()), its
new capability sets are calculated according to the following formula:
pI_new = pI
pP_new = (X & fP) | (fI & pI)
SEED Document 2
pE_new = pP_new if fE == true
pE_new = empty if fE == false
A value ending with 11new” indicates the newly calculated value. A value beginning with a p indicates a
process capability. A value beginning with an f indicates a file capability. X indicates capability bounding
set. This work is done by cap bprm apply creds() in linux/security/commoncap.c.

上述是使用exec的流程。下面是使用fork和clone的效果。
>Nothing special happens during fork() or clone(). Child processes and threads are given an exact
copy of the capabilities of the parent process.