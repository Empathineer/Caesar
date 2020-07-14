# Caesar
Implements a program that encrypts messages using Caesar’s cipher, per the below.


Background
Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

To be clear, then, here’s how encrypting HELLO with a key of 1 yields IFMMP:

<table>
  <thead>
    <tr>
      <th>plaintext</th>
      <th>H</th>
      <th>E</th>
      <th>L</th>
      <th>L</th>
      <th>O</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>+ key</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <td>= ciphertext</td>
      <td>I</td>
      <td>F</td>
      <td>M</td>
      <td>M</td>
      <td>P</td>
    </tr>
  </tbody>
</table>
More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci, in the ciphertext, c, is computed as

ci = (pi + k) % 26

wherein % 26 here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as 0, B (or b) as 1, …, H (or h) as 7, I (or i) as 8, …, and Z (or z) as 25. Suppose that Caesar just wants to say Hi to someone confidentially using, this time, a key, k, of 3. And so his plaintext, p, is Hi, in which case his plaintext’s first character, p0, is H (aka 7), and his plaintext’s second character, p1, is i (aka 8). His ciphertext’s first character, c0, is thus K, and his ciphertext’s second character, c1, is thus L. Can you see why?

Let’s write a program called caesar that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.

Here are a few examples of how the program might work. For example, if the user inputs a key of 1 and a plaintext of HELLO:

<pre class="highlight"><code>$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
</code></pre>

<p>Here’s how the program might work if the user provides a key of <code class="highlighter-rouge">13</code> and a plaintext of <code class="highlighter-rouge">hello, world</code>:</p>

<pre class="highlight"><code>$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
</code></pre>

How about one more? Here’s how the program might work if the user provides a key of 13 again, with a more complex plaintext:


<pre class="highlight"><code>$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar
</code></pre>

Why?
Notice that the case of the original message has been preserved. Lowercase letters remain lowercase, and uppercase letters remain uppercase.

And what if a user doesn’t cooperate?

<pre class="highlight"><code>$ ./caesar HELLO
Usage: ./caesar key
</code></pre>

<pre class="highlight"><code>$ ./caesar
Usage: ./caesar key
</code></pre>

<pre class="highlight"><code>$ ./caesar 1 2 3
Usage: ./caesar key
</code></pre>

Specification: 
Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.

<ul class="fa-ul">
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Implement your program in a file called <code class="highlighter-rouge">caesar.c</code> in a <code class="highlighter-rouge">~/pset2/caesar</code> directory.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program must accept a single command-line argument, a non-negative integer. Let’s call it <em>k</em> for the sake of discussion.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with <code class="highlighter-rouge">printf</code>) and return from <code class="highlighter-rouge">main</code> a value of <code class="highlighter-rouge">1</code> (which tends to signify an error) immediately.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>If any of the characters of the command-line argument is not a decimal digit, your program should print the message <code class="highlighter-rouge">Usage: ./caesar key</code> and return from <code class="highlighter-rouge">main</code> a value of <code class="highlighter-rouge">1</code>.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Do not assume that <em>k</em> will be less than or equal to 26. Your program should work for all non-negative integral values of <em>k</em> less than 2^31 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for <em>k</em> that’s too big or almost too big to fit in an <code class="highlighter-rouge">int</code>. (Recall that an <code class="highlighter-rouge">int</code> can overflow.) But, even if <em>k</em> is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if <em>k</em> is 27, <code class="highlighter-rouge">A</code> should not become <code class="highlighter-rouge">[</code> even though <code class="highlighter-rouge">[</code> is 27 positions away from <code class="highlighter-rouge">A</code> in ASCII, per http://www.asciichart.com/[asciichart.com]; <code class="highlighter-rouge">A</code> should become <code class="highlighter-rouge">B</code>, since <code class="highlighter-rouge">B</code> is 27 positions away from <code class="highlighter-rouge">A</code>, provided you wrap around from <code class="highlighter-rouge">Z</code> to <code class="highlighter-rouge">A</code>.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program must output <code class="highlighter-rouge">plaintext:</code> (without a newline) and then prompt the user for a <code class="highlighter-rouge">string</code> of plaintext (using <code class="highlighter-rouge">get_string</code>).</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program must output <code class="highlighter-rouge">ciphertext:</code> (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by <em>k</em> positions; non-alphabetical characters should be outputted unchanged.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.</li>
  <li data-marker="*"><span class="fa-li"><i class="fas fa-circle"></i></span>After outputting ciphertext, you should print a newline. Your program should then exit by returning <code class="highlighter-rouge">0</code> from <code class="highlighter-rouge">main</code>.</li>
</ul>
