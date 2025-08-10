# Stuff to learn and implement

## Text processing & simple NLP

- Learn: tokenization, normalisation (lowercase, punctuation), simple rule-based entity extraction.

- Crates: regex, whatlang (language detection, optional), tokenizers (Hugging Face Rust bindings).

- Mini-check: extract intents/entities with regex + simple token checks.

## Intent classification (classical ML)

- Learn: TF-IDF / bag-of-words and a small classifier (Naive Bayes / logistic).

- Crates: linfa (Rust ML toolkit), linfa-text or smartcore (depending on available algorithms).

- Mini-check: train a tiny classifier locally on a handful of example sentences and wire it to the CLI.

## Embeddings & pretrained models (optional but powerful)

- Learn: sentence embeddings for semantic matching and small retrieval.

- Crates: rust-bert (transformers in Rust), tokenizers (fast tokenization), tch/tch-rs (PyTorch bindings used by rust-bert).

- Mini-check: compute embeddings of a set of canned help messages and pick the nearest for user queries.

## State & dialog management

- Learn: design conversation state with enums/structs, simple FSM for multi-turn flows, timeouts.

- Pattern: enum ConversationState { Idle, AwaitingDuration, AwaitingConfirmation, ... }

- Mini-check: implement a set timer flow that asks follow-ups and remembers pending state.

> ChatGPT generated TODO(Ironic isn't it!)
