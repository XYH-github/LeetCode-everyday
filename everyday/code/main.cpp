#include "Print.h"

//#include "21_8_28-sum_for_onedimenarray.cpp"
//#include "21_8_29-sum_for_oddlength_array.cpp"
//#include "21_9_2-linedlist_get_reciprocal.cpp"
//#include "21_9_5-rank7_gene_rank10.cpp"
//#include "21_9_30-area_for_retang.cpp"
//#include "21_8_30-selete_num_by_weight.cpp"
//#include "21_10_2-dec2tohex.cpp"
//#include "21_10_3-fraction2todec.cpp"
//#include "21_10_10-sumfor_1234.cpp"
//#include "21_10_9-dataflow_to_array.cpp"
//#include "21_10_8-get_repeat_form_dna.cpp"
//#include "21_10_11-num_to_english_format.cpp"
//#include "21_10_30-single-number.cpp"
//#include "21_11_3-rainwater-connection.cpp"
//#include "21_11_8-game-for-guest-digital.cpp"
//#include "21_11_7-sum-for-range.cpp"
//#include "21_11_6-missing-num.cpp"
//#include "21_11_5-longest-arithmetic-sunsequence.cpp"
//#include "21_11_4-vaild-perfect-square.cpp"
//#include "21_11_17-maximum-product-of-word-lengths.cpp"
//#include "21_11_16-perfect-rectangle.cpp"
//#include "21_11_19-integer-replacement.cpp"
//#include "21_11_22-bulb-switcher.cpp"
//#include "21_11_13-detect-capital.cpp"
//#include "21_11_12-guess-number-high-or-lower-ii.cpp"
//#include "21_11_11-k-inverse-pairs-array.cpp"
//#include "21_11_10-teemo-attacking.cpp"
//#include "21_11_23-buddy-strings.cpp"
//#include "21_10_29-self-crossing.cpp"
//#include "21_11_25-pig-die.cpp"
//#include "21_11_29-k-th-smallest-prime-fraction.cpp"
//#include "21_12_6-truncate-sentence.cpp"
//#include "21_12_5-super-pow.cpp"
//#include "21_12_7-coloring-a-border.cpp"
//#include "21_12_4-ransom-note.cpp"
//#include "21_12_3-maximize-sum-of-array-after-k-negations.cpp"
//#include "21_12_8-maximum-sum-of-3-non-overlapping-subarrays.cpp"
//#include "21_12_2-relative-ranks.cpp"
//#include "21_12_1-consecutive-characters.cpp"
//#include "21_12_9-valid-tic-tac-toe-state.cpp"
//#include "21_11_30-nth-digit.cpp"
//#include "21_11_29-hebing-paixulianbiao.cpp"
//#include "21_11_28-find-all-anagrams-in-a-string.cpp"
//#include "21_12_19-find-the-town-judeg.cpp"
//#include "21_12_21-day-of-the-year.cpp"
//#include "22_1_1-convert-1d-array-into-2d-array.cpp"
//#include "21_12_20-heaters.cpp"
//#include "22_1_2-elimination-game.cpp"
//#include "22_1_7-maximum-nesting-depth-of-the-parentheses.cpp"
//#include "22_1_9-slowest-key.cpp"
//#include "22_1_10-additive-number.cpp"
//#include "22_1_11-escape-a-large-maze.cpp"
//#include "22_1_15-calculate-money-in-leetcode-bank.cpp"
//#include "22_1_16-linked-list-random-node.cpp"
//#include "22_1_18-minimum-time-difference.cpp"
//#include "22_1_19-contains-duplicate-ii.cpp"
//#include "22_1_17-count-vowels-permutation.cpp"
//#include "22_1_8-gray-code.cpp"
//#include "22_1_4-cat-and-mouse.cpp"
//#include "22_1_20-stone-game-ix.cpp"
//#include "22_1_26-detect-squares.cpp"
//#include "22_1_25-count-of-matches-in-tournament.cpp"
//#include "22_1_24-second-minimum-time-to-reach-destination.cpp"
//#include "22_1_27-number-of-valid-words-in-a-sentence.cpp"
//#include "22_1_28-the-number-of-weak-characters-in-the-game.cpp"
//#include "22_1_30-uncommon-words-from-two-sentences.cpp"
//#include "22_1_23-stock-price-fluctuation.cpp"
//#include "22_1_29-map-of-highest-peak.cpp"
//#include "22_2_2-reverse-prefix-of-word.cpp"
//#include "22_2_1-zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t.cpp"
//#include "22_2_1-longest-substring-with-at-least-k-repeating-characters.cpp"
//#include "22_2_3-find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k.cpp"
//#include "22_2_4-number-of-rectangles-that-can-form-the-largest-square.cpp"
//#include "22_2_5-path-with-maximum-gold.cpp"
//#include "22_2_6-sum-of-unique-elements.cpp"
//#include "22_2_7-longest-happy-string.cpp"
//#include "22_2_8-grid-illumination.cpp"
//#include "22_2_9-count-number-of-pairs-with-absolute-difference-k.cpp"
//#include "22_2_10-simplified-fractions.cpp"
//#include "22_2_11-minimum-difference-between-highest-and-lowest-of-k-scores.cpp"
//#include "22_1_31-number-of-steps-to-reduce-a-number-to-zero.cpp"
//#include "22_2_12-number-of-enclaves.cpp"
//#include "22_2_13-maximum-number-of-balloons.cpp"
//#include "22_2_14-single-element-in-a-sorted-array.cpp"
//#include "22_2_15-lucky-numbers-in-a-matrix.cpp"
//unwork #include "22_2_16-number-of-ways-to-reconstruct-a-tree.cpp"
//#include "22_2_17-knight-probability-in-chessboard.cpp"
//#include "22_2_18-find-center-of-star-graph.cpp"
//#include "22_2_19-pancake-sorting.cpp"
//#include "22_2_20-1-bit-and-2-bit-characters.cpp"
//#include "22_2_21-push-dominoes.cpp"
//unwork #include "22_2_22-the-number-of-good-subsets.cpp"
//#include "22_2_23-reverse-only-letters.cpp"
//#include "22_2_24-where-will-the-ball-fall.cpp"
//#include "22_2_25-complex-number-multiplication.cpp"
//#include "22_2_26-maximum-difference-between-increasing-elements.cpp"
//#include "22_2_27-optimal-division.cpp"
//#include "22_2_28-maximum-number-of-achievable-transfer-requests.cpp"
//#include "22_3_1-zigzag-conversion.cpp"
//#include "22_3_2-find-the-closest-palindrome.cpp"
//#include "22_3_3-add-digits.cpp"
//#include "22_3_4-sum-of-subarray-ranges.cpp"
//#include "22_3_5-minimum-time-to-finish-the-race.cpp"
//#include "22_3_6-palindromic-substrings.cpp"
//#include "22_3_6-replace-non-coprime-numbers-in-array.cpp"
//#include "22_3_6-append-k-integers-with-minimal-sum.cpp"
//#include "22_3_6-find-good-days-to-rob-the-bank.cpp"
//#include "22_3_7-base-7.cpp"
//#include "22_3_8-plates-between-candles.cpp"
//#include "22_3_9-smallest-rotation-with-highest-score.cpp"
//#include "22_3_10-n-ary-tree-preorder-traversal.cpp"
//#include "22_3_11-count-nodes-with-the-highest-score.cpp"
//#include "22_3_31-self-dividing-numbers.cpp"
//#include "22_3_30-find-servers-that-handled-most-number-of-requests.cpp"
//#include "22_3_29-max-consecutive-ones-iii.cpp"
//#include "22_3_29-maximize-the-confusion-of-an-exam.cpp"
//#include "22_3_29-longest-repeating-character-replacement.cpp"
//#include "22_3_28-binary-number-with-alternating-bits.cpp"
//#include "22_3_27-find-missing-observations.cpp"
//#include "22_3_26-baseball-game.cpp"
//#include "22_3_25-factorial-trailing-zeroes.cpp"
//#include "22_3_24-image-smoother.cpp"
//#include "22_3_23-k-th-smallest-in-lexicographical-order.cpp"
//#include "22_3_22-remove-colored-pieces-if-both-neighbors-are-the-same-color.cpp"
//#include "22_3_21-two-sum-iv-input-is-a-bst.cpp"
//#include "22_3_20-the-time-when-the-network-becomes-idle.cpp"
//#include "22_3_19-construct-string-from-binary-tree.cpp"
//#include "22_3_18-simple-bank-system.cpp"
//#include "22_3_17-longest-word-in-dictionary.cpp"
//#include "22_3_16-all-oone-data-structure.cpp"
//#include "22_3_15-count-number-of-maximum-bitwise-or-subsets.cpp"
//#include "22_3_14-minimum-index-sum-of-two-lists.cpp"
//#include "22_3_13-utf-8-validation.cpp"
//#include "22_3_12-n-ary-tree-postorder-traversal.cpp"
//#include "22_4_6-minimum-height-trees.cpp"
//#include "22_4_5-prime-number-of-set-bits-in-binary-representation.cpp"
//#include "22_4_4-range-sum-query-mutable.cpp"
//#include "22_4_3-find-smallest-letter-greater-than-target.cpp"
//unwork #include "22_4_2-strong-password-checker.cpp"
//#include "22_4_1-array-of-doubled-pairs.cpp"
//#include "22_4_7-rotate-string.cpp"
//#include "22_4_8-n-ary-tree-level-order-traversal.cpp"
//#include "22_4_9-reaching-points.cpp"
//#include "22_4_10-unique-morse-code-words.cpp"
//#include "22_4_11-count-numbers-with-unique-digits.cpp"
//#include "22_4_12-number-of-lines-to-write-string.cpp"
//#include "22_4_13-insert-delete-getrandom-o1.cpp"
//#include "22_4_14-richest-customer-wealth.cpp"
//#include "22_4_15-mini-parser.cpp"
//#include "22_4_16-largest-palindrome-product.cpp"
//#include "22_4_17-most-common-word.cpp"
//#include "22_4_18-lexicographical-numbers.cpp"
//#include "22_4_19-shortest-distance-to-a-character.cpp"
//#include "22_4_20-longest-absolute-file-path.cpp"
//#include "22_4_21-goat-latin.cpp"
//#include "22_4_22-rotate-function.cpp"
//unwork #include "22_4_23-erect-the-fence.cpp"
//#include "22_4_24-binary-gap.cpp"
//#include "22_4_25-random-pick-index.cpp"
//#include "22_4_26-projection-area-of-3d-shapes.cpp"
//#include "22_4_27-pacific-atlantic-water-flow.cpp"
//#include "22_4_28-sort-array-by-parity.cpp"
//#include "22_4_29-construct-quad-tree.cpp"
//#include "22_4_30-smallest-range-i.cpp"

//#include "22_6_1-partition-to-k-equal-sum-subsets.cpp"
//#include "22_6_1-matchsticks-to-square.cpp"
//#include "22_6_2-delete-node-in-a-bst.cpp"
//#include "22_6_3-consecutive-numbers-sum.cpp"
//#include "22_6_4-unique-email-addresses.cpp"
//#include "22_6_5-generate-random-point-in-a-circle.cpp"
//#include "22_6_6-my-calendar-iii.cpp"
//#include "22_6_7-koko-eating-bananas.cpp"
//#include "22_6_8-valid-boomerang.cpp"
//#include "22_6_9-random-point-in-non-overlapping-rectangles.cpp"
//#include "22_6_10-count-different-palindromic-subsequences.cpp" 
//#include "22_6_11-flip-string-to-monotone-increasing.cpp"
//#include "22_6_12-find-and-replace-pattern.cpp"
//#include "22_6_13-height-checker.cpp"
//#include "22_6_14-diagonal-traverse.cpp"
//#include "22_6_15-find-k-th-smallest-pair-distance.cpp"
//#include "22_6_16-k-diff-pairs-in-an-array.cpp"
//#include "22_6_17-duplicate-zeros.cpp"
//#include "22_6_18-4ueAj6.cpp"
//#include "22_6_19-most-frequent-subtree-sum.cpp"
//#include "22_6_20-range-module.cpp"

// 
//#include "22_5_30-sum-of-root-to-leaf-binary-numbers.cpp"
//#include "22_5_29-validate-ip-address.cpp"
//#include "22_5_28-remove-outermost-parentheses.cpp"
//#include "22_5_27-find-closest-lcci.cpp"
//#include "22_5_26-falling-squares.cpp"
//#include "22_5_25-unique-substrings-in-wraparound-string.cpp"
//#include "22_5_24-univalued-binary-tree.cpp"
//#include "22_5_23-cut-off-trees-for-golf-event.cpp"
//#include "22_5_22-nim-game.cpp"
//#include "22_5_22-can-i-win.cpp"
//#include "22_5_21-n-repeated-element-in-size-2n-array.cpp"
//#include "22_5_20-find-right-interval.cpp"
//#include "22_5_19-find-kth-largest-xor-coordinate-value.cpp"
//#include "22_5_19-kth-largest-element-in-an-array.cpp"
//#include "22_5_19-minimum-moves-to-equal-array-elements-ii.cpp"
//#include "22_5_18-kth-smallest-number-in-multiplication-table.cpp"
//#include "22_5_17-verifying-an-alien-dictionary.cpp"
//#include "22_5_16-successor-lcci.cpp"
//#include "22_5_15-largest-triangle-area.cpp"
//#include "22_5_14-stickers-to-spell-word.cpp"
//#include "22_5_13-one-away-lcci.cpp"
//#include "22_5_13-edit-distance.cpp"
//#include "22_5_12-delete-columns-to-make-sorted.cpp"
//#include "22_5_11-serialize-and-deserialize-binary-tree.cpp"
//#include "22_5_11-serialize-and-deserialize-bst.cpp"
//#include "22_5_9-di-string-match.cpp" 
//#include "22_5_8-find-all-duplicates-in-an-array.cpp"
//#include "22_5_7-minimum-genetic-mutation.cpp"
//#include "22_5_6-number-of-recent-calls.cpp"
//#include "22_5_5-subarray-product-less-than-k.cpp"
//#include "22_5_4-find-the-winner-of-the-circular-game.cpp"
//#include "22_5_3-reorder-data-in-log-files.cpp"
//#include "22_5_2-tag-validator.cpp"
//#include "22_5_1-all-elements-in-two-binary-search-trees.cpp"


//#include "22_1_21-jump-game-iv.cpp"
//#include "22_1_22-remove-palindromic-subsequences.cpp"
//#include "22_1_12-increasing-triplet-subsequence.cpp"
//#include "22_1_13-largest-number-at-least-twice-of-others.cpp"
//#include "22_1_14-kth-smallest-element-in-a-sorted-matrix.cpp"
//#include "22_1_14-ugly-number-ii.cpp"
//#include "22_1_14-find-k-pairs-with-smallest-sums.cpp"
//#include "22_1_3-day-of-the-week.cpp"
//#include "22_1_5-replace-all-s-to-avoid-consecutive-repeating-characters.cpp"
//#include "22_1_6-simplify-path.cpp"
//#include "21_12_10-shortest-completing-word.cpp"
//#include "21_12_11-online-election.cpp"
//#include "21_12_12-to-lower-case.cpp"
//#include "21_12_13-trapping-rain-water.cpp"
//#include "21_12_13-max-increase-to-keep-city-skyline.cpp"
//#include "21_12_14-single-element-in-a-sorted-array.cpp"
//#include "21_12_14-course-schedule-iii.cpp"
//#include "21_12_14-course-schedule.cpp"
//#include "21_12_15-lucky-numbers-in-a-matrix.cpp"
//#include "21_12_14-course-schedule-iv.cpp"
//#include "21_12_15-loud-and-rich.cpp"
//#include "21_12_16-maximum-number-of-visible-points.cpp"
//#include "21_12_17-water-bottles.cpp"
//#include "21_12_18-battleships-in-a-board.cpp"
//#include "21_12_22-repeated-string-match.cpp"
//#include "21_12_23-longest-duplicate-substring.cpp"
//#include "21_12_24-maximum-number-of-eaten-apples.cpp"
//#include "21_12_25-even-odd-tree.cpp"
//#include "21_12_26-occurrences-after-bigram.cpp"
//#include "21_12_27-friends-of-appropriate-ages.cpp"
//#include "21_12_28-concatenated-words.cpp"
//#include "21_12_28-implement-trie-prefix-tree.cpp"
// 
//#include "21_12_29-count-special-quadruplets.cpp"
//#include "21_12_30-hand-of-straights.cpp"
//#include "21_12_31-perfect-number.cpp"
//#include "21_11_26-search-in-a-binary-search-tree.cpp"
//#include "21_11_27-random-flip-matrix.cpp"

//#include "temp.cpp"


int main(void) {
	//string input = "heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]];";
	//Print<string>::VectorFormTrans(input);
	//cout << input << endl;

}


