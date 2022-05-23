# Authdeez

Authdeez it's an (experimental) authenticator (like Google Authenticator) for desktops systems.

## Dependencies

Openssl (libcrypto)

## Compilling

```
meson subprojects download
meson setup build
meson compile -C build
```

## Testing

After compiling, you can find all tests in `./build/all_tests` (quite intuitive huh?).

## Running

Check accounts.example.txt for store keys in a file and rename it to `accounts.txt`.

Run with `./build/authdeez/`.

## Example 

[![asciicast](https://asciinema.org/a/lobBsF6thxhBKq2GysMqOoV4f.svg)](https://asciinema.org/a/lobBsF6thxhBKq2GysMqOoV4f)

## Milestones

- [ ] protect accounts.txt with a password
