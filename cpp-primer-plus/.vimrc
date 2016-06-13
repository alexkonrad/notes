" Automatically compiles and executes the current file
nnoremap <leader>c :w<CR>:!g++ % && ./a.out<CR>

" Pastes the program template file into the buffer
nnoremap <leader>t :r ./template.cpp<CR>kddA

" Insert-mode keyboard shortcuts for I/O
:imap cout <<  cout << ut << 
:imap cin >>  cin >> n >> 
:imap <<   << 
:imap >>   >> 
