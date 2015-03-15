# FAQ for Field3D #

<br>

<h2>General questions</h2>

<h3>Where should I send questions, comments or suggestions?</h3>

Please join the <a href='http://groups.google.com/group/field3d-dev'>field3d-dev group</a> and post there. That way all the developers and other users have a chance to help answer your questions.<br>
<br>
<h3>How do I submit a bug?</h3>

If you come across something that's an obvious bug and doesn't require discussion, then just open a ticket under the "Issues" tab at the top. Provide as much detail as you can. If the problem requires some discussion to determine the best fix we prefer to hold the discussion on the email list - so please join the <a href='http://groups.google.com/group/field3d-dev'>field3d-dev group</a> and post there.<br>
<br>
<h3>How do I contribute back to the project?</h3>

If it's your first contribution to the project, we prefer that you open an Issue ticket and post your patch there for review. Frequent contributors will get commit access to make the process easier.<br>
<br>
Also, before we can accept code you need to fill out a Contributor License Agreement. Instructions and PDFs are available at the <a href='http://opensource.imageworks.com/cla/'>Imageworks Open Source web site</a>.<br>
<br>
<br>

<h2>Questions about the file format and data structures</h2>

<h3>Field3d mentions both generic (and presumably slow) voxel access as well as direct (and fast) access. Please explain.</h3>

The Field base class provides both virtual functions for access to voxel data (the <code>value()</code> function) as well as iterators for traversing all the voxels in a field. The iterators simply call the <code>value()</code> function, but makes it easy to loop over an entire field.<br>
<br>
When coding directly against a known data structure, e.g. <code>DenseField&lt;float&gt;</code>, the <code>fastValue()</code> call is non-virtual (virtual functions can be unusually slow in threaded applications). Also, the <code>DenseField</code> template class provides const and non-const iterators specifically written for it, which are faster than the generic <code>Field::const_iterator</code> and <code>WritableField::iterator</code>.<br>
<br>
Most likely an application would be written so that it deals with data in the direct, more efficient manner. However, it could also implement routines for handling unknown field types through the generic interface. This future-proofs the application, in that new data structures can be supported that were unavailable when the application first was written, simply by recompiling against the latest library version, or by extending the set of available subclasses through the use of plugins.<br>
<br>
<h3>Can each layer/field have its own resolution?</h3>

Yes, there is no limitation on the resolution of a field in relationship to another field in the same file, even with the same field name and/or attribute name. Each field's mapping may also be different.<br>
<br>
<h3>Can the fields be offset in space or do they have to be coincident in space?</h3>

Just as the resolution (extents and data window) may be different, each field may have its own unique mapping, and each mapping may be of a different type. For example, a <code>MatrixFieldMapping</code> may be used on one field while another uses some custom mapping type, for example a frustum-aligned mapping.