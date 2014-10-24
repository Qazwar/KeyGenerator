Key Generator
=============

#Description

This is example realization of key generator, which was a task in Binary Studio Academy 2013 for C++ group.

Key generator should generates keys by few rules:

 * key is a set of \<letter\>\<number\> which is separated by dash;
 * forbidden letters are D, F, G, J, M, Q, V, 0;
 * start key is "A1";
 * terminate set for extending key is "Z9";
 * maximum length of key is 10 groups of \<letter\>\<number\> sequence.

Key generator function should take key and return incremented key. For example:

```
"A2-B9" -> "A2-C1"
"B5-Z9" -> "B6-A1"
"Z9-Z9-Z9" -> "A1-A1-A1-A1"
```

#Sample

Realization is designed to be customized via template arguments of `KeyGeneratorImp` class. Thus in folder `Sample` you can find example of customized key generator, which increments binary keys. For example:

```
"00001111" -> "000010000"
```

#Environment

Code was written in Eclipse with CDT plugin, so for building you need to import root of repository into your workspace. Project `KeyGeneratorTests` requires tunned `gtest` library  in system.